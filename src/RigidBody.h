
#pragma once

#include <Corrade/Containers/Pointer.h>

#include <btBulletDynamicsCommon.h>
#include <Magnum/BulletIntegration/Integration.h>
#include <Magnum/BulletIntegration/MotionState.h>

namespace MOSP
{
    class Object;

    class RigidBody
    {
        Object& m_object;
        Magnum::BulletIntegration::MotionState *m_mState;
        btDynamicsWorld *m_bWorld{nullptr};
        btRigidBody *m_bRigidBody{nullptr};
    public:
        RigidBody(MOSP::Object&);
        btRigidBody *bulletRigidBody() { return m_bRigidBody; }
        const btRigidBody *bulletRigidBody() const { return m_bRigidBody; }
        void set(btRigidBody*);
        void syncTransform();
    };
}
