
#include "Gui.h"
#include <Gui/SceneGraph.h>
#include <Corrade/Utility/Debug.h>

using namespace MOSP::Gui;

void Gui::doStats()
{
    ImGui::Begin("Debug info", &m_showStats);
    ImGui::Text("Hello, world!");
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
        1000.0/Magnum::Double(ImGui::GetIO().Framerate), Magnum::Double(ImGui::GetIO().Framerate));

//     ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiCond_FirstUseEver);
}

void Gui::doDemo()
{
    ImGui::ShowDemoWindow();
}

void Gui::doHierarchy()
{
    if (ImGui::Begin("Objects hierarchy", &m_showHierarchy))
    {
        if (m_hierarchyObj)
        {
            auto *clicked = HierarchyWidget(m_hierarchyObj);
            if (clicked != nullptr)
                m_currentObj = clicked;
        }
        else
            ImGui::Text("No object selected.");
        ImGui::End();
    }
}

void Gui::doCurrentObjectInfo()
{
    if (ImGui::Begin("Current object info", &m_showCurrent))
    {
        if (m_currentObj)
            ObjectInfoWidget(m_currentObj);
        else
            ImGui::Text("No object selected.");
        ImGui::End();
    }
}

void Gui::doAll()
{
    if (!m_showGui)  return;
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("View"))
        {
            ImGui::MenuItem("Show GUI", "I", &m_showGui);
            ImGui::MenuItem("Demo window", "", &m_showDemo);
            ImGui::MenuItem("Stats window", "", &m_showStats);
            ImGui::MenuItem("Currents hierarchy window", "", &m_showHierarchy);
            ImGui::MenuItem("Current object window", "", &m_showCurrent);
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
    if (m_showStats)  doStats();
    if (m_showHierarchy)  doHierarchy();
    if (m_showCurrent)  doCurrentObjectInfo();
    if (m_showDemo)  doDemo();
}
