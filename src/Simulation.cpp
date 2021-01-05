
#include <Corrade/Utility/Debug.h>
#include <Corrade/Containers/Array.h>
#include <Magnum/Math/Color.h>

#include <Magnum/GL/Renderer.h>
#include <Magnum/Math/Color.h>
// #include <Magnum/SceneGraph/Camera.h>
#include <Simulation.h>

using namespace Magnum;
using namespace Magnum::Math;
using namespace Magnum::Math::Literals;
using namespace MOSP;

void ColoredDrawable::draw(const MOSP::Matrix4& transformationMatrix, MOSP::Camera3D& camera) {
    _shader
        .setDiffuseColor(_color)
        .setLightPositions({
            {Magnum::MatrixTypeFor<3, Float>(camera.cameraMatrix()).transformPoint({-3.0f, 10.0f, 10.0f}), 0.0f}
        })
        .setTransformationMatrix(Magnum::Matrix4(transformationMatrix))
        .setNormalMatrix(Magnum::Matrix3(transformationMatrix.normalMatrix()))
        .setProjectionMatrix(Magnum::Math::Matrix4<Float>(camera.projectionMatrix()))
        .draw(_mesh);
}



Simulation::Simulation()
{
    _phongShader.setAmbientColor(0x111111_rgbf)
        .setSpecularColor(0xffffff_rgbf)
        .setShininess(80.0f);
}

MOSP::Object *Simulation::createColoredObject(Magnum::GL::Mesh& mesh, const Magnum::Color4 color, MOSP::Matrix4 transform, MOSP::Object *parent)
{
    auto *obj = new MOSP::Object();
    if (parent == nullptr)
        obj->setParent(&_root);
    else
        obj->setParent(parent);

    obj->setTransformation(transform);
    new ColoredDrawable(*obj, _phongShader, mesh, color, _drawables);

    return obj;
}

void Simulation::draw()
{
    m_camMan.camera().draw(_drawables);
}
