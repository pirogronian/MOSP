#include <Corrade/Utility/DebugStl.h>
#include <Corrade/Containers/GrowableArray.h>
#include <Magnum/GL/Context.h>
#include <Magnum/GL/Renderer.h>
#include <Magnum/GL/Version.h>
#include <Magnum/Math/Color.h>
#include <Magnum/Primitives/Cone.h>
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
        void viewportEvent(ViewportEvent& ) override;

        void setupSimulation();
//         Corrade::Containers::GrowableArray<Magnum::GL::Mesh> _glmeshes;
        Simulation _sim;
};

using namespace Math::Literals;

MospApplication::MospApplication(const Arguments& arguments): Platform::Application{arguments, Configuration{}
    .setTitle("MOSP")
    .setWindowFlags(Configuration::WindowFlag::Resizable)}
{
    GL::Renderer::setClearColor(0x404040_rgbf);
    setupSimulation();
}

void MospApplication::drawEvent() {
    GL::defaultFramebuffer.clear(GL::FramebufferClear::Color);

    _sim.draw();

    swapBuffers();
}

void MospApplication::viewportEvent(ViewportEvent& event) {
    GL::defaultFramebuffer.setViewport({{}, event.framebufferSize()});
    _sim.camera().setViewport(event.windowSize());
}

void MospApplication::setupSimulation() {
    _sim.cameraObject().translate(MOSP::SceneGraph::Vector3::zAxis(5.0));
    _sim.camera().setAspectRatioPolicy(Magnum::SceneGraph::AspectRatioPolicy::Extend)
        .setProjectionMatrix(MOSP::SceneGraph::Matrix4::perspectiveProjection(35.0_deg, 1.0, 0.01, 1000.0))
        .setViewport(GL::defaultFramebuffer.viewport().size());
    auto *mesh = new GL::Mesh(MeshTools::compile(Primitives::coneSolid(2, 16, 1)));
    _sim.createColoredObject(*mesh, 0xa5c9ea_rgbf, MOSP::SceneGraph::Matrix4::translation({0, 0, 0}));
}

MAGNUM_APPLICATION_MAIN(MospApplication)
