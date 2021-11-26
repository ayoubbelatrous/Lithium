#include "Inspector.h"
#include "glm/glm.hpp"
#include <glm/gtc/type_ptr.hpp>
#include "Scene/Components.h"
void Inspector::Init(Lithium::Ref<Scene> scene)
{
	_context = scene;
}

static void DrawVec3Control(const std::string& label, glm::vec3& values, float resetValue = 0.0f, float columnWidth = 100.0f)
{
	ImGuiIO& io = ImGui::GetIO();
	auto boldFont = io.Fonts->Fonts[1];

	ImGui::PushID(label.c_str());

	ImGui::Columns(2);
	ImGui::SetColumnWidth(0, columnWidth);
	ImGui::Text(label.c_str());
	ImGui::NextColumn();

	ImGui::PushMultiItemsWidths(3, ImGui::CalcItemWidth());
	ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2{ 0, 0 });

	float lineHeight = GImGui->Font->FontSize + GImGui->Style.FramePadding.y * 2.0f;
	ImVec2 buttonSize = { lineHeight + 3.0f, lineHeight };

	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.8f, 0.1f, 0.15f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.9f, 0.2f, 0.2f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.8f, 0.1f, 0.15f, 1.0f });
	ImGui::PushFont(boldFont);
	if (ImGui::Button("X", buttonSize))
		values.x = resetValue;
	ImGui::PopFont();
	ImGui::PopStyleColor(3);

	ImGui::SameLine();
	ImGui::DragFloat("##X", &values.x, 0.1f, 0.0f, 0.0f, "%.2f");
	ImGui::PopItemWidth();
	ImGui::SameLine();

	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.2f, 0.7f, 0.2f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.3f, 0.8f, 0.3f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.2f, 0.7f, 0.2f, 1.0f });
	ImGui::PushFont(boldFont);
	if (ImGui::Button("Y", buttonSize))
		values.y = resetValue;
	ImGui::PopFont();
	ImGui::PopStyleColor(3);

	ImGui::SameLine();
	ImGui::DragFloat("##Y", &values.y, 0.1f, 0.0f, 0.0f, "%.2f");
	ImGui::PopItemWidth();
	ImGui::SameLine();

	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.1f, 0.25f, 0.8f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.2f, 0.35f, 0.9f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.1f, 0.25f, 0.8f, 1.0f });
	ImGui::PushFont(boldFont);
	if (ImGui::Button("Z", buttonSize))
		values.z = resetValue;
	ImGui::PopFont();
	ImGui::PopStyleColor(3);

	ImGui::SameLine();
	ImGui::DragFloat("##Z", &values.z, 0.1f, 0.0f, 0.0f, "%.2f");
	ImGui::PopItemWidth();

	ImGui::PopStyleVar();

	ImGui::Columns(1);

	ImGui::PopID();
}



void Inspector::RenderUI()
{
	ImGuiIO& io = ImGui::GetIO();

	auto boldFont = io.Fonts->Fonts[1];

	ImGui::Begin("Inspector");
	auto& name = selection.GetComponent<TagComponent>().Name;
	char buffer[256];
	memset(buffer, 0, sizeof(buffer));
	std::strncpy(buffer, name.c_str(), sizeof(buffer));
	if (ImGui::InputText("##Tag", buffer, sizeof(buffer)))
	{
		name = std::string(buffer);
	}



	if (selection.HasComponent<TransformComponent>())
	{
		ImGui::PushFont(boldFont);
		ImGui::Selectable("Transform");
		ImGui::PopFont();
		ImGui::Separator();
		DrawVec3Control("Position", selection.GetComponent<TransformComponent>().Position);
		ImGui::Separator();
		DrawVec3Control("Rotation", selection.GetComponent<TransformComponent>().Rotation);
		ImGui::Separator();
		DrawVec3Control("Scale", selection.GetComponent<TransformComponent>().Scale);
		ImGui::Separator();

	}
	
	if (selection.HasComponent<SpriteRendererComponent>())
	{
		ImGui::PushFont(boldFont);
		ImGui::Selectable("Sprite Renderer");
		ImGui::PopFont();
		ImGui::Separator();
		ImGui::ColorEdit4("Color",glm::value_ptr(selection.GetComponent<SpriteRendererComponent>().Color));
	}


	ImGui::End();
}


void Inspector::DrawComponent(Entity entity)
{

}

void Inspector::SetSelection(Entity entity)
{
	selection =  entity;
}

