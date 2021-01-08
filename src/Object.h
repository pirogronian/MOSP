
#pragma once

#include <Corrade/Containers/Pointer.h>
#include <RigidBody.h>
#include <Utils/AutoIndexer.h>
#include "SceneGraph.h"

namespace MOSP
{

    class Object : public Object3D
    {
        static MOSP::Utils::AutoIndexer<Object*> m_indexer;
        std::size_t m_id;

        Corrade::Containers::Pointer<MOSP::RigidBody> m_rigidBody{nullptr};
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

        bool hasRigidBody() const { return (bool)m_rigidBody; }
        RigidBody *rigidBody() { return m_rigidBody.get(); }
        const RigidBody *rigidBody() const { return m_rigidBody.get(); }
    };
}
