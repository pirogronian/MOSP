
#pragma once

#include <Corrade/Containers/LinkedList.h>
#include <imgui.h>
#include <Object.h>
#include "StateWidget.h"

namespace MOSP
{
    namespace Gui
    {
        class Gui
        {
            Corrade::Containers::LinkedList<MOSP::Gui::StateWidget> m_widgetList;
        public:
            void insert(MOSP::Gui::StateWidget *w) { m_widgetList.insert(w); }
            void remove(MOSP::Gui::StateWidget *w) { m_widgetList.erase(w); }
            Object3D *m_currentObj{nullptr};
            Object3D *m_hierarchyObj{nullptr};
            bool m_showGui{true};
            bool m_showDemo{false};
            bool m_showStats{false};
            bool m_showHierarchy{false};
            bool m_showCurrent{false};
            void doStateWidgets();
            void doDemo();
            void doStats();
            void doHierarchy();
            void doCurrentObjectInfo();
            void doAll();
        };

        Gui& getDefault();
    }
}
