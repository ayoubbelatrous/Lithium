#pragma once
#include "Lithium.h"

class Application
{
private:
	Window _window;
public:
	virtual void Init();
	virtual void Render();
	virtual void Delete();
	int shouldClose() const;
	GLFWwindow* GetWindow()
	{
		return _window.GetWindow();
	}
};



