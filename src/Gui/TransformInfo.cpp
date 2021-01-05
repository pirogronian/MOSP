
#include "TransformInfo.h"

namespace ns = MOSP::Gui;

void ns::TransformInfoWidget(const MOSP::Vector3& v)
{
    ImGui::Text("X: %f", v[0]);
    ImGui::Text("Y: %f", v[1]);
    ImGui::Text("Z: %f", v[2]);
}
