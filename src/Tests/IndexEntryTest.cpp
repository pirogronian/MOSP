
#include <Utils/IndexEntry.h>

using namespace MOSP::Utils;

struct TIE
{
    MapIndexEntry<int, TIE> m_intIndex;
//     TIE() : m_intIndex(*this)
};

template class MapIndexEntry<int, TIE>;

int main()
{
    return 0;
}
