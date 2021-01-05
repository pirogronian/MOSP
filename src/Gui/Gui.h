
#pragma once

#include <imgui.h>
#include <Object.h>

namespace MOSP
{
    namespace Gui
    {
        class Gui
        {
        public:
            Object3D *m_currentObj{nullptr};
            Object3D *m_hierarchyObj{nullptr};
            bool m_showGui{true};
            bool m_showDemo{false};
            bool m_showStats{false};
            bool m_showHierarchy{false};
            bool m_showCurrent{false};
            void doDemo();
            void doStats();
            void doHierarchy();
            void doCurrentObjectInfo();
            void doAll();
        };
    }
}
