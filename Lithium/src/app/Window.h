#pragma once
#include "glfw3.h"


class Window
{
private:
	GLFWwindow* _window;
public:
	Window();
	~Window();

	void Init(int width = 500, int height = 500);
	

};
