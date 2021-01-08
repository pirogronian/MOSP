
#pragma once

#include <Corrade/Containers/Pointer.h>
#include <RigidBody.h>
#include <Utils/AutoIndexedClass.h>
#include <Utils/NamedClassInstance.h>
#include "SceneGraph.h"

namespace MOSP
{

    class Object : 
        public Object3D,
        public MOSP::Utils::AutoIndexedClass<Object>,
        public MOSP::Utils::NamedClassInstance<Object>
    {
        Corrade::Containers::Pointer<MOSP::RigidBody> m_rigidBody{nullptr};
    public:
        Object(Object *parent = nullptr) : Object3D(parent) {}
        Object(Scene3D *parent) : Object3D(parent) {}
        ~Object();

        bool hasRigidBody() const { return (bool)m_rigidBody; }
        RigidBody *rigidBody() { return m_rigidBody.get(); }
        const RigidBody *rigidBody() const { return m_rigidBody.get(); }
    };
}
