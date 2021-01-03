
#include "Object.h"
#include "Scene.h"

using namespace MOSP::SceneGraph;

Object::Object(Object *parent) : Object3D(parent)
{
    
}

Object::Object(Scene *parent) : Object3D(static_cast<Object3D*>(parent))
{
    
}

Object& Object::setParent(Object *parent)
{
    Object3D::setParent(parent);
    return *this;
}

Object& Object::setParent(Scene *parent)
{
    Object3D::setParent(static_cast<Object3D*>(parent));
    return *this;
}

Scene *Object::scene()
{
    return dynamic_cast<Scene*>(Object3D::scene());
}

const Scene *Object::scene() const
{
    return dynamic_cast<const Scene*>(Object3D::scene());
}
