
#include "RigidBody.h"

using namespace Corrade;
using namespace MOSP;

RigidBody::RigidBody(SceneGraph::Object3D* parent, Magnum::Float mass, btCollisionShape* bShape, btDynamicsWorld& bWorld): SceneGraph::Object3D{parent}, m_bWorld(bWorld) {
    /* Calculate inertia so the object reacts as it should with
        rotation and everything */
    btVector3 bInertia(0.0f, 0.0f, 0.0f);
    if(!Magnum::Math::TypeTraits<Magnum::Float>::equals(mass, 0.0f))
        bShape->calculateLocalInertia(mass, bInertia);

    /* Bullet rigid body setup */
    auto* motionState = new Magnum::BulletIntegration::MotionState{*this};
    m_bRigidBody.emplace(btRigidBody::btRigidBodyConstructionInfo{
        mass, &motionState->btMotionState(), bShape, bInertia});
    m_bRigidBody->forceActivationState(DISABLE_DEACTIVATION);
    bWorld.addRigidBody(m_bRigidBody.get());
}
