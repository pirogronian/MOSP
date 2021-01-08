#include <Corrade/Utility/DebugStl.h>
#include <Corrade/Containers/GrowableArray.h>
#include <Magnum/GL/Context.h>
#include <Magnum/GL/Renderer.h>
#include <Magnum/GL/Version.h>
#include <Magnum/Math/Color.h>
#include <Magnum/Primitives/Cone.h>
#include <Magnum/Primitives/Cube.h>
#include <Magnum/MeshTools/Compile.h>
#include <Magnum/Trade/MeshData.h>
#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/GL/Mesh.h>
#include <Magnum/Platform/Sdl2Application.h>
#include <Magnum/ImGuiIntegration/Context.hpp>

#include <SceneGraph.h>
#include "Simulation.h"
#include "ViewportRotation.h"
#include <Gui/SceneGraph.h>
#include <Gui/Gui.h>

using namespace Magnum;
// using namespace Magnum::Platform::Application;
using namespace MOSP;

class MospApplication: public Platform::Application {
    public:
        explicit MospApplication(const Arguments& arguments);

    private:
        void drawEvent() override;
        void viewportEvent(ViewportEvent&) override;
        void keyPressEvent(KeyEvent&) override;
        void keyReleaseEvent(KeyEvent&) override;
        void textInputEvent(TextInputEvent&) override;
        void mouseScrollEvent(MouseScrollEvent&) override;
        void mousePressEvent(MouseEvent&) override;
        void mouseReleaseEvent(MouseEvent&) override;
        void mouseMoveEvent(MouseMoveEvent&) override;

        void drawGUI();
        void testMouseRotation(const Magnum::Vector2i &);

        void setupSimulation();
        Magnum::ImGuiIntegration::Context m_imgui{NoCreate};
        Simulation _sim;
        ViewportRotation m_vrot;

};

using namespace Magnum::Math::Literals;

MospApplication::MospApplication(const Arguments& arguments): Platform::Application{arguments, Configuration{}
    .setTitle("MOSP")
    .setWindowFlags(Configuration::WindowFlag::Resizable)}
{
    GL::Renderer::setBlendEquation(GL::Renderer::BlendEquation::Add,
        GL::Renderer::BlendEquation::Add);
    GL::Renderer::setBlendFunction(GL::Renderer::BlendFunction::SourceAlpha,
        GL::Renderer::BlendFunction::OneMinusSourceAlpha);

    GL::Renderer::setClearColor(0x404040_rgbf);
    m_imgui = ImGuiIntegration::Context(Vector2{windowSize()}/dpiScaling(),
        windowSize(), framebufferSize());
    ImGui::GetIO().FontGlobalScale = 1.5;
    setupSimulation();
    m_vrot.setViewport(windowSize());
}

void MospApplication::drawEvent() {
    GL::defaultFramebuffer.clear(GL::FramebufferClear::Color|GL::FramebufferClear::Depth);

    GL::Renderer::enable(GL::Renderer::Feature::DepthTest);
    GL::Renderer::enable(GL::Renderer::Feature::FaceCulling);
    GL::Renderer::disable(GL::Renderer::Feature::ScissorTest);
    GL::Renderer::disable(GL::Renderer::Feature::Blending);
    _sim.draw();

    drawGUI();

    swapBuffers();
    redraw();
}

void MospApplication::viewportEvent(ViewportEvent& event) {
    GL::defaultFramebuffer.setViewport({{}, event.framebufferSize()});
    m_imgui.relayout(Vector2{event.windowSize()}/event.dpiScaling(),
        event.windowSize(), event.framebufferSize());
    _sim.camera().setViewport(event.windowSize());
    m_vrot.setViewport(event.windowSize());
}

void MospApplication::keyPressEvent(KeyEvent& event) {
    if(m_imgui.handleKeyPressEvent(event)) return;
//     Corrade::Utility::Debug{} << "Unused keyPressEvent:" << event.keyName();
    if (event.isRepeated()) return;
    if (event.key() == KeyEvent::Key::I)
        Gui::getDefault().m_showGui = !Gui::getDefault().m_showGui;
}

void MospApplication::keyReleaseEvent(KeyEvent& event) {
    if(m_imgui.handleKeyReleaseEvent(event)) return;
//     Corrade::Utility::Debug{} << "Unused keyReleaseEvent:" << event.keyName();
}

void MospApplication::textInputEvent(TextInputEvent& event) {
    if(m_imgui.handleTextInputEvent(event)) return;
}

void MospApplication::mouseScrollEvent(MouseScrollEvent& event) {
    if(m_imgui.handleMouseScrollEvent(event)) {
        /* Prevent scrolling the page */
        event.setAccepted();
        return;
    }
    if(!event.offset().y()) return;

    /* Move 15% of the distance back or forward */
    _sim.cameraManipulator().changeDistanceByFactor(1.0f - (event.offset().y() > 0 ? 1/0.85f : 0.85f));

    redraw();
}

void MospApplication::mousePressEvent(MouseEvent& event)
{
    if(m_imgui.handleMousePressEvent(event)) return;
    if(event.button() == MouseEvent::Button::Right)
        m_vrot.start(event.position());
}

void MospApplication::mouseReleaseEvent(MouseEvent& event)
{
    if(m_imgui.handleMouseReleaseEvent(event)) return;
    if(event.button() == MouseEvent::Button::Left)
        m_vrot.end();
//     if (m_gui.m_debuggedObj)
//     {
//         Corrade::Utility::Debug{} << "D object transform:\n" << m_gui.m_debuggedObj->transformationMatrix();
//         Corrade::Utility::Debug{} << " translation:\n" << m_gui.m_debuggedObj->transformationMatrix().translation();
//         Corrade::Utility::Debug{} << " rotation M:\n" << m_gui.m_debuggedObj->transformationMatrix().rotation();
//         Corrade::Utility::Debug{} << " rotation E:\n" << toEuler(m_gui.m_debuggedObj->transformationMatrix().rotation());
//     }
}

void MospApplication::mouseMoveEvent(MouseMoveEvent& event)
{
    if(m_imgui.handleMouseMoveEvent(event)) return;
    if(!(event.buttons() & MouseMoveEvent::Button::Right)) return;

    m_vrot.update(event.position());
    _sim.cameraManipulator().rotateRoot(m_vrot.lastAngle(), m_vrot.lastAxis());
//     Corrade::Utility::Debug{} << "Mouse pos:" << event.position();
    redraw();
}

void MospApplication::drawGUI()
{
    m_imgui.newFrame();

    if(ImGui::GetIO().WantTextInput && !isTextInputActive())
        startTextInput();
    else if(!ImGui::GetIO().WantTextInput && isTextInputActive())
        stopTextInput();

    Gui::getDefault().doAll();
    /* Update application cursor */
    m_imgui.updateApplicationCursor(*this);

    GL::Renderer::disable(GL::Renderer::Feature::DepthTest);
    GL::Renderer::disable(GL::Renderer::Feature::FaceCulling);
    GL::Renderer::enable(GL::Renderer::Feature::ScissorTest);
    GL::Renderer::enable(GL::Renderer::Feature::Blending);
    m_imgui.drawFrame();
}

void MospApplication::testMouseRotation(const Magnum::Vector2i &v)
{
    m_vrot.start(Magnum::Vector2i{0, 0});
    m_vrot.update(v);
    m_vrot.end();
    _sim.cameraManipulator().rotateRoot(m_vrot.lastAngle(), m_vrot.lastAxis());
}

void MospApplication::setupSimulation() {
    _sim.cameraManipulator().setAbsoluteDistance(5);
    _sim.cameraManipulator().setAbsoluteDistance(5);
    _sim.camera().setAspectRatioPolicy(Magnum::SceneGraph::AspectRatioPolicy::Extend)
        .setProjectionMatrix(MOSP::Matrix4::perspectiveProjection(35.0_deg, 1.0, 0.01, 1000.0))
        .setViewport(GL::defaultFramebuffer.viewport().size());
    auto *coneMesh = new GL::Mesh(MeshTools::compile(Primitives::coneSolid(2, 16, 1)));
    auto *cubeMesh = new GL::Mesh(MeshTools::compile(Primitives::cubeSolid()));
    auto cone = _sim.createColoredObject(*coneMesh, 0xa5c9ea_rgbf, MOSP::Matrix4::translation({0, 0, 0}));
    cone->setClassInstanceName("Cone");
    _sim.cameraManipulator().rootObject();
    Gui::getDefault().m_hierarchyObj = &_sim.rootObject();
}

MAGNUM_APPLICATION_MAIN(MospApplication)
