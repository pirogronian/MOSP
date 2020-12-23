
#include "SceneGraph.h"

namespace MOSP
{
    class CameraManipulator {
        SceneGraph::Object3D m_manipulator;
        SceneGraph::Object3D m_camObject;
        SceneGraph::Camera3D m_camera;
    public:
        CameraManipulator(SceneGraph::Object3D *parent) :
            m_manipulator{parent}, m_camObject(&m_manipulator), m_camera(m_camObject)
        {
        }
        SceneGraph::Camera3D& camera() { return m_camera; }
        void setAbsoluteDistance(double d)
        {
            m_camObject.resetTransformation();
            m_camObject.translate(SceneGraph::Vector3::zAxis(d));
        }
        double getAbsoluteDistance() const
        {
            return m_camObject.transformation().translation().z();
        }
        void changeDistance(float delta)
        {
            m_camObject.translate(SceneGraph::Vector3::zAxis(delta));
        }
        void changeDistanceByFactor(float factor)
        {
            float d = m_camObject.transformation().translation().z();
            m_camObject.translate(SceneGraph::Vector3::zAxis(d * factor));
        }
    };
}
