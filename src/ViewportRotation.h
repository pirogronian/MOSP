
#include <Magnum/Math/Vector3.h>
#include "Math.h"

namespace MOSP
{
    class ViewportRotation
    {
    protected:
        Magnum::Vector3 m_prevPos;
        Magnum::Vector3 m_lastAxis;
        Magnum::Vector2i m_viewport;
        Math::Angle m_lastAngle;
        bool m_active {false};
    public:
        void setViewport(const Magnum::Vector2i size) { m_viewport = size; }
        void start(const Magnum::Vector2i pos) { m_prevPos = positionOnSphere(pos); m_active = true; }
        void end() { m_prevPos = Magnum::Vector3(); m_active = false; }
        void update(const Magnum::Vector2i&);
        Magnum::Vector3 positionOnSphere(const Magnum::Vector2i& position) const;
        Math::Angle lastAngle() const { return m_lastAngle; }
        Magnum::Vector3 lastAxis() const { return m_lastAxis.normalized(); }
    };
}
