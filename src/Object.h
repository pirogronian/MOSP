
#pragma once

#include <Corrade/Containers/Pointer.h>
#include <BulletDynamics/Dynamics/btRigidBody.h>
#include <Magnum/BulletIntegration/MotionState.h>
#include <Utils/AutoIndexer.h>
#include "SceneGraph.h"

namespace MOSP
{

    class Object : public Object3D
    {
        static MOSP::Utils::AutoIndexer<Object> m_indexer;
        std::size_t m_id;

        Corrade::Containers::Pointer<btRigidBody> m_rigidBody{nullptr};
        Corrade::Containers::Pointer<Magnum::BulletIntegration::MotionState> m_motionState{nullptr};
    public:
        Object(Object *parent = nullptr) : Object3D(parent)
        {
            m_id = m_indexer.add(this);
        }
        Object(Scene3D *parent) : Object3D(parent)
        {
            m_id = m_indexer.add(this);
        }
        ~Object();

        std::size_t id() const { return m_id; }

        bool hasRigidBody() const { return m_rigidBody != nullptr; }
        void syncRigidBodyTransform();
    };
}
