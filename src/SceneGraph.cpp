
#include "Magnum/SceneGraph/MatrixTransformation3D.hpp"
#include "Magnum/SceneGraph/Object.hpp"
#include "Magnum/SceneGraph/Drawable.hpp"
#include "Magnum/SceneGraph/AbstractFeature.hpp"
#include <Magnum/SceneGraph/FeatureGroup.hpp>
#include <Magnum/SceneGraph/Camera.hpp>

#include <Utils/AutoIndexer.h>

using namespace Magnum;

template class Magnum::SceneGraph::BasicMatrixTransformation3D<Magnum::Double>;

template class Magnum::SceneGraph::Object<Magnum::SceneGraph::BasicMatrixTransformation3D<Magnum::Double>>;

template class Magnum::SceneGraph::Drawable<3, Magnum::Double>;

template class Magnum::SceneGraph::AbstractGroupedFeature<3, Magnum::SceneGraph::Drawable<3, Magnum::Double>, Magnum::Double>;

template class Magnum::SceneGraph::AbstractFeature<3, Double>;

template class Magnum::SceneGraph::Camera<3, Magnum::Double>;

template class Magnum::SceneGraph::AbstractFeatureGroup<3, Magnum::Double>;

template class Magnum::SceneGraph::FeatureGroup<3, Magnum::SceneGraph::Drawable<3, Magnum::Double>, Magnum::Double>;

// template class Magnum::Math::Matrix4<Double>;

template class MOSP::Utils::AutoIndexer<Magnum::SceneGraph::Object<Magnum::SceneGraph::BasicMatrixTransformation3D<Magnum::Double>>>;
