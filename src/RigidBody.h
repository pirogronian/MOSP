
#include "Bullet.h"

#include <Corrade/Containers/Pointer.h>
#include <Magnum/Math/Constants.h>
#include <Magnum/BulletIntegration/Integration.h>
#include <Magnum/BulletIntegration/MotionState.h>
#include <Magnum/BulletIntegration/DebugDraw.h>
#include "SceneGraph.h"

namespace MOSP
{

class RigidBody: public SceneGraph::Object3D {
    public:
        RigidBody(SceneGraph::Object3D*, Magnum::Float, btCollisionShape*, btDynamicsWorld& );

        ~RigidBody() {
            m_bWorld.removeRigidBody(m_bRigidBody.get());
        }

        btRigidBody& bulletRigidBody() { return *m_bRigidBody; }

        /* needed after changing the pose from Magnum side */
        void syncPose() {
            m_bRigidBody->setWorldTransform(btTransform(transformationMatrix()));
        }

    private:
        btDynamicsWorld& m_bWorld;
        Corrade::Containers::Pointer<btRigidBody> m_bRigidBody;
};
}
