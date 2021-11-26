#include "Application.h"
#include <fstream>
#include <string> 
#include <sstream>



void Application::Init()
{

	
	
	_window = Window();

	_window.Init(500,500);
	glewInit();

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	std::cout << glGetString(GL_VERSION) << std::endl;
	int texture_units;
	glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &texture_units);
	std::cout << texture_units << std::endl;
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	glFrontFace(GL_CW);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}
void Application::Render()
{
	
	
	_window.Run();
	
}


/*
void Application::UIRender()
{
	
	ImGui::Begin("Seeker");
	ImGui::DragFloat3("position", &pos.x, 0.01f,-3.0f, 3.0f);
	ImGui::DragFloat3("rotation", &rot.x, 0.01f, -3.0f, 3.0f);
	ImGui::DragFloat3("scale", &sca.x, 0.01f, -3.0f, 3.0f);
	ImGui::DragFloat("size", &orthosize);
	ImGui::ColorEdit4("Background", &background.r);
	ImGui::Text("Texture");
	ImGui::Image((void*)(intptr_t)tex->GetID(), ImVec2(256, 256), ImVec2{ 0, 1 }, ImVec2{ 1, 0 });
	
	ImGui::End();
	ImGui::Begin("Debug");
	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	ImGui::Checkbox("Render", &draw);
	ImGui::End();
	
	ImGui::Begin("Scene");

	viewportSize = glm::vec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y);
	
	
	ImGui::Image((void*)(intptr_t)fb->GetColorAttachmentID(), ImVec2(viewportSize.x, viewportSize.y), ImVec2{ 0, 1 }, ImVec2{ 1, 0 });

	auto viewportMinRegion = ImGui::GetWindowContentRegionMin();
	auto viewportMaxRegion = ImGui::GetWindowContentRegionMax();
	auto viewportOffset = ImGui::GetWindowPos();
	m_ViewportBounds[0] = { viewportMinRegion.x + viewportOffset.x, viewportMinRegion.y + viewportOffset.y };
	m_ViewportBounds[1] = { viewportMaxRegion.x + viewportOffset.x, viewportMaxRegion.y + viewportOffset.y };



	glm::mat4 _view = view;
	glm::mat4 _proj = proj;
	matrix = model;

	
	ImGuizmo::SetOrthographic(true);
	ImGuizmo::SetDrawlist();

	ImGuizmo::SetRect(m_ViewportBounds[0].x, m_ViewportBounds[0].y, m_ViewportBounds[1].x - m_ViewportBounds[0].x, m_ViewportBounds[1].y - m_ViewportBounds[0].y);
	ImGuizmo::Manipulate(glm::value_ptr(_view), glm::value_ptr(_proj),
	(ImGuizmo::OPERATION)ImGuizmo::OPERATION::TRANSLATE, ImGuizmo::WORLD, glm::value_ptr(matrix));

	if (ImGuizmo::IsUsing())
	{
		pos = matrix[3];
	}

	ImGui::End();


	ImGui::Begin("Console");
	ImGui::End();

}
*/

void Application::Delete()
{
	glfwTerminate();
	std::cout << "still running" << std::endl;
	exit(0);
}

int Application::shouldClose() const
{
	return _window.shouldClose();
}
