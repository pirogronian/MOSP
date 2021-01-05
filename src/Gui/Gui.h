
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
            Object3D *m_debuggedObj{nullptr};
            Object3D *m_hierarchyObj{nullptr};
            bool m_showGui{false};
            bool m_showDebug{false};
            bool m_showDemo{false};
            void doDebug();
            void doDemo();
            void doAll();
        };
    }
}
