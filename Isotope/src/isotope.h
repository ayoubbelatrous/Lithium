#pragma once
#include "Lithium.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
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
};