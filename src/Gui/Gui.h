
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
            static Corrade::Containers::LinkedList<MOSP::Gui::StateWidget> m_widgetList;
        public:
            void insert(MOSP::Gui::StateWidget *w) { m_widgetList.insert(w); }
            void remove(MOSP::Gui::StateWidget *w) { m_widgetList.erase(w); }
            static Object3D *m_currentObj;
            static Object3D *m_hierarchyObj;
            static bool m_showGui;
            static bool m_showDemo;
            static bool m_showStats;
            static bool m_showHierarchy;
            static bool m_showCurrent;
            static void doStateWidgets();
            static void doDemo();
            static void doStats();
            static void doHierarchy();
            static void doCurrentObjectInfo();
            static void doAll();
        };
    }
}
