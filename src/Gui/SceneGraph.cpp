
#include <Gui/SceneGraph.h>
#include <Object.h>

namespace ns = MOSP::Gui;

void ns::HierarchyWidget(MOSP::Object3D *)
{
    
}

void ns::ObjectInfoWidget(MOSP::Object3D *obj)
{
    auto pos = obj->transformationMatrix().translation();
    ImGui::Text("Position:");
    ImGui::Text("X: %f", pos.x());
    ImGui::Text("Y: %f", pos.y());
    ImGui::Text("Z: %f", pos.z());
    ImGui::Text("Rotation:");
    
}
