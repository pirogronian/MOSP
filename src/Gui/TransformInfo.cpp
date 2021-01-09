
#include "TransformInfo.h"

namespace ns = MOSP::Gui;

void ns::TransformInfoWidget(const MOSP::Vector3& v)
{
    ImGui::Text("X: %f", v[0]);
    ImGui::Text("Y: %f", v[1]);
    ImGui::Text("Z: %f", v[2]);
}

void ns::TransformInfoWidget(const MOSP::Matrix4& m)
{
    if (ImGui::BeginTable("TransformationMatrixTable", 4))
    {
        for(std::size_t col = 0; col < 4; col++)
        {
            ImGui::TableNextColumn();
            for(std::size_t row = 0; row < 4; row++)
            {
//                 ImGui::TableNextRow();
                ImGui::Text("%f", m[col][row]);
            }
        }
        ImGui::EndTable();
    }
}
