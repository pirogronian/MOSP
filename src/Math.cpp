
#define _USE_MATH_DEFINES

#include <cmath>
#include <Math.h>

using namespace MOSP;

Vector3 MOSP::toEuler(const Magnum::Matrix3x3d& mrot)
{
    Vector3 ret;

    if (mrot[0][2] == 1 || mrot[2][0] == -1)
    {
        ret[2] = 0;
        auto delta = std::atan2(mrot[0][1], mrot[0][2]);
        if (mrot[0][2] == -1)
        {
            ret[1] = -M_PI / 2;
            ret[0] = -ret[2] + delta;
        }
        else
        {
            ret[1] = -M_PI / 2;
            ret[0] = -ret[2] + delta;
        }
    }
    else
    {
        ret[1] = -std::asin(mrot[0][2]);
        ret[0] = std::atan2(mrot[1][2] / std::cos(ret[1]), mrot[2][2] / std::cos(ret[1]));
        ret[2] = std::atan2(mrot[0][1] / std::cos(ret[1]), mrot[0][0] / std::cos(ret[1]));
    }

    return ret;
}
