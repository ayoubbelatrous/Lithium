#pragma once
#include "Lithium.h"

class Application
{
private:
	Window _window;
public:
	void Init();
	void Render();
	void Delete();
	int shouldClose() const;
	GLFWwindow* GetWindow()
	{
		return _window.GetWindow();
	}
};



