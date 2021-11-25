#pragma once
#include "GL/glew.h"
#include "glm/glm.hpp"


#define ASSERT(x) \
	if (!(x))\
		__debugbreak();

#define GLCall(x)\
	ClearGLError();\
	x;             \
	ASSERT(LogGLCall(#x, __FILE__, __LINE__))

void ClearGLError();
bool LogGLCall(const char* name, const char* file, int line);


namespace Renderer{

	static void Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	static void ClearColor(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	static void Draw(int count)
	{
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
	}


}



