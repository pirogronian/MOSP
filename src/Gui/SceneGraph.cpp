
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
    int flags = ImGuiTreeNodeFlags_OpenOnArrow;
    if (obj->children().isEmpty()) flags |= ImGuiTreeNodeFlags_Leaf;
    if (mobj)
        opened = ImGui::TreeNodeEx(obj,
                                   flags,
                                   "(%i) \"%s\"",
                                   mobj->classAutoIndexValue(),
                                   mobj->classInstanceName().data());
    else
        opened = ImGui::TreeNodeEx(obj, flags, "(Basic)");
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
    if (ImGui::CollapsingHeader("Transformations"))
    {
        auto matrix = obj->transformationMatrix();
        if (ImGui::CollapsingHeader("Euler"))
        {
            auto pos = matrix.translation();
            ImGui::BeginGroup();
            ImGui::Text("Position:");
            ns::TransformInfoWidget(pos);
            ImGui::EndGroup();
            ImGui::SameLine();
            ImGui::BeginGroup();
            ImGui::Text("Rotation:");
            auto rot = MOSP::toEuler(matrix.rotation());
            ns::TransformInfoWidget(rot);
            ImGui::EndGroup();
        }
        if (ImGui::CollapsingHeader("Matrix"))
        {
            ns::TransformInfoWidget(matrix);
        }
    }
}
