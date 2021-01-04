
#include "SceneGraph.h"
#include <SceneGraph/Object.h>

namespace ns = MOSP::Gui::Debug::SceneGraph;

void ns::HierarchyWidget(MOSP::SceneGraph::Object &)
{
    
}

void ns::ObjectInfoWidget(MOSP::SceneGraph::Object &obj)
{
    auto pos = obj.transformationMatrix().translation();
    ImGui::Text("Position:");
    ImGui::Text("X: %f", pos.x());
    ImGui::Text("Y: %f", pos.y());
    ImGui::Text("Z: %f", pos.z());
    ImGui::Text("Rotation:");
    
}
