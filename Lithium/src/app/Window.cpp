#include "Window.h"
#include "glfw3.h"


Window::Window()
{

}

Window::~Window()
{

}

void Window::Init(int width = 500,int height = 500)
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	_window = glfwCreateWindow(width, height, "Lithium", NULL, NULL);
}
