
#pragma once

#include <Utils/AutoIndexer.h>
#include "SceneGraph.h"

namespace MOSP
{
    namespace SceneGraph
    {

        class Object : public Object3D
        {
            static MOSP::Utils::AutoIndexer<Object> m_indexer;
            std::size_t m_id;
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
        };
    }
}
