
#include <Object.h>
#include "RigidBody.h"

using namespace MOSP;
using namespace Magnum;

RigidBody::RigidBody(Object& obj) : m_object(obj)
{
    m_mState = new BulletIntegration::MotionState(obj);
}

void RigidBody::syncTransform()
{
    if (m_bRigidBody != nullptr)
        m_bRigidBody->setWorldTransform(btTransform(m_object.transformationMatrix()));
}
