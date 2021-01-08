
#include <Corrade/Utility/Debug.h>
#include <Corrade/Containers/Pointer.h>

using namespace Corrade::Utility;
using namespace Corrade::Containers;

class Pointed
{
public:
    int member;
    Pointed(int v = -1) : member(v) {}
    ~Pointed();
};

Debug& operator << (Debug& out, const Pointed& obj)
{
    Debug{} << "Pointed{" << obj.member << "}";
    return out;
}

Pointed::~Pointed()
{
    Debug{} << *this << "destroyed!";
}

int main()
{
//     Pointer<Pointed> p1(InPlaceInitT, {2});
//     p1 = new Pointed(3);
}
