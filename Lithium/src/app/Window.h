#pragma once
#include "glfw3.h"


class Window
{
private:
	GLFWwindow* _window;
public:
	Window();
	~Window();
	void Init(int width, int height);
	void Run();
	int shouldClose() const;
	GLFWwindow* GetWindow()
	{
		return _window;
	}
};
