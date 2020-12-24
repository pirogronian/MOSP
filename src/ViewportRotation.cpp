
#include "ViewportRotation.h"

using namespace Magnum;
using namespace MOSP;

Vector3 ViewportRotation::positionOnSphere(const Vector2i& position) const {
    const Vector2 positionNormalized = Vector2{position}/Vector2{m_viewport} - Vector2{0.5f};
    const Float length = positionNormalized.length();
    const Vector3 result(length > 1.0f ? Vector3(positionNormalized, 0.0f) : Vector3(positionNormalized, 1.0f - length));
    return (result * Vector3::yScale(-1.0f)).normalized();
}

void ViewportRotation::update(const Vector2i& position)
{
    if (!m_active)  return;

    const Vector3 currentPosition = positionOnSphere(position);
    m_lastAxis = Magnum::Math::cross(m_prevPos, currentPosition);

    if(m_prevPos.length() < 0.001f || m_lastAxis.length() < 0.001f) return;

    if (!m_prevPos.isNormalized() || !currentPosition.isNormalized())
    {
        Corrade::Utility::Debug{} << "ViewportRotation::update(" << position << "): cannot normalize vectors:" << m_prevPos << currentPosition;
        return;
    }
    m_lastAngle = Magnum::Math::angle(m_prevPos, currentPosition);
    m_prevPos = currentPosition;
}
