
#pragma once

#include <Utils/NonOwningLinkedList.h>

namespace MOSP
{
    namespace Gui
    {
        class StateWidget : public MOSP::Utils::NonOwningLinkedListItem<StateWidget>
        {
        public:
            virtual void doGui() = 0;
            virtual ~StateWidget() = 0;
        };
    }
}
