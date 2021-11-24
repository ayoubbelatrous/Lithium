#include "Window.h"
#include "glfw3.h"


Window::Window()
{
	glfwInit();
}

Window::~Window()
{

}

void Window::Init(int width,int height)
{
	
	_window = glfwCreateWindow(width, height, "Lithium", NULL, NULL);

	glfwMakeContextCurrent(_window);
}

void Window::Run()
{
	glfwSwapBuffers(_window);
	glfwPollEvents();
}

int Window::shouldClose() const
{
	return glfwWindowShouldClose(_window);
}
