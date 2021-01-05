
#include <Magnum/Math/Angle.h>
#include <Magnum/Math/Vector3.h>
#include <Magnum/Math/Matrix.h>

#include <Magnum/Magnum.h>
// #include <>

namespace MOSP
{
    typedef Magnum::Math::Rad<Magnum::Float> Angle;
    typedef Magnum::Math::Rad<Magnum::Double> Rad;
    typedef Magnum::Math::Vector3<Magnum::Double> Vector3;
    typedef Magnum::Math::Matrix3<Magnum::Double> Matrix3;
    typedef Magnum::Math::Matrix4<Magnum::Double> Matrix4;

    Vector3 toEuler(const Magnum::Matrix3x3d &);
}
