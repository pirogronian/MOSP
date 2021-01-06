
#include <Magnum/BulletIntegration/Integration.h>

#include "Object.h"

using namespace MOSP;

Object::~Object()
{
    m_indexer.remove(m_id);
}

void Object::syncRigidBodyTransform()
{
    if (m_rigidBody != nullptr)
        m_rigidBody->setWorldTransform(btTransform(transformationMatrix()));
}

MOSP::Utils::AutoIndexer<Object> Object::m_indexer;

