
#pragma once

#include "SceneGraph.h"

namespace MOSP
{
    namespace SceneGraph
    {
        class Scene;

        class Object : public Object3D
        {
            std::size_t m_sceneIndex;
            Object3D& setParent(Object3D *);
        public:
            Object(Object *parent = nullptr);
            Object(Scene *parent);

            std::size_t sceneIndex() const { return m_sceneIndex; }
            Object& setParent(Object *);
            Object& setParent(Scene *);
            Scene *scene();
            const Scene *scene() const;
        };
    }
}
