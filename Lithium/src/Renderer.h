#pragma once
#include "GL/glew.h"


#define ASSERT(x) \
	if (!(x))\
		__debugbreak();

#define GLCall(x)\
	ClearGLError();\
	x;             \
	ASSERT(LogGLCall(#x, __FILE__, __LINE__))

void ClearGLError();
bool LogGLCall(const char* name, const char* file, int line);
