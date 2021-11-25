#include "Renderer.h"
#include <iostream>

void ClearGLError()
{
	while (glGetError() != GL_NO_ERROR)
		;
}

bool LogGLCall(const char* name, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "{GL Error} (" << error << "): " << name << std::endl;
		return false;
	}
	return true;
}

class Renderer
{

};


