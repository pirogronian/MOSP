
#include "SceneGraph.h"

namespace ns = MOSP::Gui::Debug::SceneGraph;

void ns::HierarchyWidget(MOSP::SceneGraph::Object3D &)
{
}

void ns::ObjectInfoWidget(MOSP::SceneGraph::Object3D &obj)
{
    auto pos = obj.transformationMatrix().translation();
    ImGui::Text("Position:");
    ImGui::Text("X: %f", pos.x());
    ImGui::Text("Y: %f", pos.y());
    ImGui::Text("Z: %f", pos.z());
    ImGui::Text("Rotation:");
    
}
