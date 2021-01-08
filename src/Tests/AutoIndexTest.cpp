
#include <array>
#include <Corrade/Utility/Debug.h>
#include <Utils/AutoIndexer.h>

struct TestClass
{
    int member;
};

using namespace Corrade::Utility;
using namespace MOSP::Utils;

template class AutoIndexer<TestClass*>;

int main()
{
    std::array<TestClass, 15> ta;
    AutoIndexer<TestClass*> ai;
    for(int i = 0; i < ta.size(); i++)
    {
        ta[i].member = ta.size() - i;
        ai.add(&(ta[i]));
    }
    Debug{} << ai;
    assert(ai.size() == 15);
    assert(ai.firstFreeSlot() == AutoIndexer<TestClass>::InvalidIndex);
    assert(ai.freeSlots() == 0);

    ai.remove(3);
    ai.remove(7);
    ai.remove(14);
    Debug{} << ai;
    assert(ai.size() == 14);
    assert(ai.firstFreeSlot() == 3);
    assert(ai.freeSlots() == 2);

    ai.add(&ta[3]);
    Debug{} << ai;
    assert(ai.size() == 14);
    assert(ai.firstFreeSlot() == 7);
    assert(ai.freeSlots() == 1);

    return 0;
}
