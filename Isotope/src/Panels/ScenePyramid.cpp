#include "ScenePyramid.h"
#include "imgui/imgui.h"

#include "Scene/Components.h"



void ScenePyramid::DrawEntity(Entity entity) {


	ImGui::PushStyleColor(ImGuiCol_Header, ImVec4(0.25f, 0.25f, 0.25f, 1.00f));
	auto& tag = entity.GetComponent<TagComponent>().Name;
	ImGuiTreeNodeFlags flags = ((selection == entity) ? ImGuiTreeNodeFlags_Selected : 0) | ImGuiTreeNodeFlags_OpenOnArrow;
	flags |= ImGuiTreeNodeFlags_SpanAvailWidth;
	flags |= ImGuiTreeNodeFlags_FramePadding;
	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(3.f, 3.f));
	ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.f, 0.f));
	bool opened = ImGui::TreeNodeEx((void*)(uint64_t)(uint32_t)entity, flags, tag.c_str());
	ImGui::PopStyleVar();
	ImGui::PopStyleVar();
	if (ImGui::IsItemClicked())
	{
		selection = entity;
	}

	bool entityDeleted = false;
	if (ImGui::BeginPopupContextItem())
	{
		if (ImGui::MenuItem("Delete Entity"))
			entityDeleted = true;

		ImGui::EndPopup();
	}

	if (opened)
	{
		ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_SpanAvailWidth;
		bool opened = ImGui::TreeNodeEx((void*)9817239, flags, tag.c_str());
		if (opened)
			ImGui::TreePop();
		ImGui::TreePop();
	}

	ImGui::PopStyleColor();

}



void ScenePyramid::Init(Lithium::Ref<Scene> scene)
{
	_context = scene;
	selection = {};
}

void ScenePyramid::RenderUI()
{
	ImGui::Begin("Pyramid");
	_context->GetReg().each([&](auto entityID)
	{
		Entity entity{ entityID , _context.get() };
		DrawEntity(entity);
		
	});


	ImGui::End();
}
