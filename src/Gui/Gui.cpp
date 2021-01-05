
#include "Gui.h"
#include <Gui/SceneGraph.h>

using namespace MOSP::Gui;

void Gui::doDebug()
{
    ImGui::Text("Hello, world!");
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
        1000.0/Magnum::Double(ImGui::GetIO().Framerate), Magnum::Double(ImGui::GetIO().Framerate));

    if (m_debuggedObj)
        ObjectInfoWidget(m_debuggedObj);
    ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiCond_FirstUseEver);
    if (m_hierarchyObj)
    {
        auto *clicked = HierarchyWidget(m_hierarchyObj);
        if (clicked != nullptr)
            m_debuggedObj = clicked;
    }
}

void Gui::doDemo()
{
    ImGui::ShowDemoWindow();
}

void Gui::doAll()
{
    if (!m_showGui)  return;
    if (m_showDebug)  doDebug();
    if (m_showDemo)  doDemo();
}
