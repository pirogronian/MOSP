
#include <Corrade/Utility/Debug.h>

#include <Utils/NonOwningLinkedList.h>

using namespace Corrade::Utility;
using namespace Corrade::Containers;
using namespace MOSP::Utils;

struct TestItem : public NonOwningLinkedListItem<TestItem>
{
    int val{13};
    TestItem() = default;
    TestItem(int v) : val(v) {}
    ~TestItem();
};

Corrade::Utility::Debug& operator<<(Corrade::Utility::Debug& out, const TestItem& item)
{
    out << "TestItem{" << item.val << "}";

    return out;
}

TestItem::~TestItem()  { Debug{} << "~" << (*this); }

Corrade::Utility::Debug& operator<<(Corrade::Utility::Debug& out, const LinkedList<TestItem>& list)
{
    for(auto &item : list)
        out << item;
    return out;
}

template class LinkedList<TestItem>;

int main()
{
    LinkedList<TestItem> list;

    auto *i1 = new TestItem(1);
    auto *i2 = new TestItem(2);
    auto *i3 = new TestItem(3);
    auto *i4 = new TestItem(4);

    list.insert(i1);
    list.insert(i2);
    list.insert(i3);
    list.insert(i4);

    Debug{} << "===1===\n" << list;

    list.erase(i1);

    Debug{} << "===2===\n" << list;

    delete i2;

    Debug{} << "===3===\n" << list;

    return 0;
}

// template class NonOwningLinkedListItem<TestItem>;
