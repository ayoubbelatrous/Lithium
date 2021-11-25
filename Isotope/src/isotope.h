#pragma once
#include "Lithium.h"
#include "Application.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "Scene/Scene.h"
#include "Scene/Entity.h"


struct TransformComponent {

	glm::vec3 Position;
	glm::vec3 Rotation;
	glm::vec3 Scale = {1,1,1};
	TransformComponent() = default;
	TransformComponent(const TransformComponent&) = default;

	glm::mat4 GetMatrix() const
	{
		glm::mat4 rotation = glm::toMat4(glm::quat(Rotation));

		return glm::translate(glm::mat4(1.0f), Position)
			* rotation
			* glm::scale(glm::mat4(1.0f), Scale);
	}

};


using namespace Lithium;
class isotope
{
	GLFWwindow* wind;
public:
	void SetWindow(GLFWwindow* win)
	{
		wind = win;
	}
	void Init();
	void Render();
	void Delete();
	void UIrender();
	Ref<FrameBuffer> fb;
	Ref<Shader> shader;
	Ref<VertexArray> va;
	Ref<VertexBufferLayout> lay;
	Ref<VertexBuffer> buf;
	Ref<IndexBuffer> ibuf;
	Ref<Texture> tex;
	glm::mat4 MVP;
	
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 proj;
	float width, height;


	ImVec2 prevsize;

	ImDrawData *data;
	Ref<Scene> scene;
	Entity entity;

};
