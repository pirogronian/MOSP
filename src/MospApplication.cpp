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

#include "SceneGraph.h"
#include "Simulation.h"

using namespace Magnum;
using namespace MOSP;

class MospApplication: public Platform::Application {
    public:
        explicit MospApplication(const Arguments& arguments);

    private:
        void drawEvent() override;
        void viewportEvent(ViewportEvent&) override;
        void mouseScrollEvent(MouseScrollEvent&) override;

        void setupSimulation();
        Simulation _sim;
};

using namespace Math::Literals;

MospApplication::MospApplication(const Arguments& arguments): Platform::Application{arguments, Configuration{}
    .setTitle("MOSP")
    .setWindowFlags(Configuration::WindowFlag::Resizable)}
{
    GL::Renderer::enable(GL::Renderer::Feature::DepthTest);
    GL::Renderer::enable(GL::Renderer::Feature::FaceCulling);
    GL::Renderer::setClearColor(0x404040_rgbf);
    setupSimulation();
}

void MospApplication::drawEvent() {
    GL::defaultFramebuffer.clear(GL::FramebufferClear::Color|GL::FramebufferClear::Depth);

    _sim.draw();

    swapBuffers();
}

void MospApplication::viewportEvent(ViewportEvent& event) {
    GL::defaultFramebuffer.setViewport({{}, event.framebufferSize()});
    _sim.camera().setViewport(event.windowSize());
}

void MospApplication::mouseScrollEvent(MouseScrollEvent& event) {
    if(!event.offset().y()) return;

    /* Distance to origin */
    const Float distance = _sim.cameraManipulator().getAbsoluteDistance();

    /* Move 15% of the distance back or forward */
    _sim.cameraManipulator().changeDistanceByFactor(1.0f - (event.offset().y() > 0 ? 1/0.85f : 0.85f));

    redraw();
}

void MospApplication::setupSimulation() {
    _sim.cameraManipulator().setAbsoluteDistance(5);
    _sim.cameraManipulator().setAbsoluteDistance(5);
    _sim.camera().setAspectRatioPolicy(Magnum::SceneGraph::AspectRatioPolicy::Extend)
        .setProjectionMatrix(MOSP::SceneGraph::Matrix4::perspectiveProjection(35.0_deg, 1.0, 0.01, 1000.0))
        .setViewport(GL::defaultFramebuffer.viewport().size());
    auto *coneMesh = new GL::Mesh(MeshTools::compile(Primitives::coneSolid(2, 16, 1)));
    auto *cubeMesh = new GL::Mesh(MeshTools::compile(Primitives::cubeSolid()));
    _sim.createColoredObject(*coneMesh, 0xa5c9ea_rgbf, MOSP::SceneGraph::Matrix4::translation({0, 0, 0}));
}

MAGNUM_APPLICATION_MAIN(MospApplication)
