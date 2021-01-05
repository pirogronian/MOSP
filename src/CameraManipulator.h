
#include <Magnum/Math/Quaternion.h>
#include "Math.h"

#include <SceneGraph.h>

namespace MOSP
{
    class CameraManipulator {
        Object3D m_manipulator;
        Object3D m_camObject;
        Camera3D m_camera;
    public:
        CameraManipulator(Object3D *parent) :
            m_manipulator{parent}, m_camObject(&m_manipulator), m_camera(m_camObject)
        {
        }
        Camera3D& camera() { return m_camera; }
        const Object3D& rootObject() const { return m_manipulator; }
        const Object3D& cameraObject() const { return m_camObject; }
        void setAbsoluteDistance(double d)
        {
            m_camObject.resetTransformation();
            m_camObject.translate(Vector3::zAxis(d));
        }
        double getAbsoluteDistance() const
        {
            return m_camObject.transformation().translation().z();
        }
        void changeDistance(float delta)
        {
            m_camObject.translate(Vector3::zAxis(delta));
        }
        void changeDistanceByFactor(float factor)
        {
            float d = m_camObject.transformation().translation().z();
            m_camObject.translate(Vector3::zAxis(d * factor));
        }
        void rotateRoot(const Magnum::Math::Quaternion<Magnum::Float>& quaternion)
        {
            m_manipulator.rotate(Magnum::Quaterniond(quaternion));
        }
        void rotateRoot(Math::Angle angle, const Magnum::Vector3& axis)
        {
            if (!axis.isNormalized())
            {
                Corrade::Utility::Debug{} << "CameraManipulator::rotateRoot(" << angle << "," << axis << "): axis not normalized!;";
                return;
            }
            m_manipulator.rotate(Rad(angle), Vector3(axis).normalized());
        }
    };
}
