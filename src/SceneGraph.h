
#include <Magnum/Math/Angle.h>
#include <Magnum/SceneGraph/MatrixTransformation3D.h>
#include <Magnum/SceneGraph/Object.h>
#include <Magnum/SceneGraph/Scene.h>
#include <Magnum/SceneGraph/Drawable.h>
#include <Magnum/SceneGraph/Camera.h>

namespace MOSP {
    typedef Magnum::SceneGraph::BasicMatrixTransformation3D<Magnum::Double> MatrixTransformation3D;

    typedef Magnum::SceneGraph::Object<MatrixTransformation3D> Object3D;

    typedef Magnum::SceneGraph::Scene<MatrixTransformation3D> Scene3D;

    typedef Magnum::SceneGraph::Drawable<3, Magnum::Double> Drawable3D;

    typedef Magnum::SceneGraph::Camera<3, Magnum::Double> Camera3D;

    typedef Magnum::SceneGraph::BasicDrawableGroup3D<Magnum::Double> DrawableGroup3D;
}
