
#include <string>
#include <Gui/SceneGraph.h>
#include <Object.h>
#include <Math.h>
#include "TransformInfo.h"

namespace ns = MOSP::Gui;

MOSP::Object3D *ns::HierarchyWidget(MOSP::Object3D *obj)
{
    bool opened;
    MOSP::Object3D *clicked = nullptr;
    MOSP::Object *mobj = dynamic_cast<MOSP::Object*>(obj);
    if (mobj)
        opened = ImGui::TreeNode(obj, "%i", mobj->id());
    else
        opened = ImGui::TreeNode(obj, "(Basic)");
    if (ImGui::IsItemClicked())
        clicked = obj;
    if (opened)
    {
        for(auto& obj : obj->children())
        {
            auto *cc = HierarchyWidget(&obj);
            if (cc != nullptr)
                clicked = cc;
        }
        ImGui::TreePop();
    }
    return clicked;
}

void ns::ObjectInfoWidget(MOSP::Object3D *obj)
{
    auto pos = obj->transformationMatrix().translation();
    ImGui::BeginGroup();
    ImGui::Text("Position:");
    ns::TransformInfoWidget(pos);
    ImGui::EndGroup();
    ImGui::SameLine();
    ImGui::BeginGroup();
    ImGui::Text("Rotation:");
    auto rot = MOSP::toEuler(obj->transformationMatrix().rotation());
    ns::TransformInfoWidget(rot);
    ImGui::EndGroup();
}
