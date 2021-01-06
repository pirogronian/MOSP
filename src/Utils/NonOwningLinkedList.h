
#include <Corrade/Containers/LinkedList.h>

namespace MOSP::Utils
{
    template<class Derived, class List = Corrade::Containers::LinkedList<Derived>>
    class NonOwningLinkedListItem : public Corrade::Containers::LinkedListItem<Derived, List>
    {
    public:
        void erase()
        {
            Corrade::Containers::LinkedListItem<Derived, List>::list()->cut(static_cast<Derived*>(this));
        }
        virtual ~NonOwningLinkedListItem()
        {
            Corrade::Containers::LinkedListItem<Derived, List>::list()->cut(static_cast<Derived*>(this));
        }
    };
}

