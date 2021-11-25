#pragma once
#include "Lithium.h"
#include "Application.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include <memory>




namespace Lithium {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}

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



};
