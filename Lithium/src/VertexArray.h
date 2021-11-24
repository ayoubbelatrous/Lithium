#pragma once
#include "Renderer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray
{
private:
	unsigned int _id;
public:
	VertexArray();
	~VertexArray();
	void UnBind() const;
	void Bind() const;
	void AddBuffer(const VertexBuffer& vb,const VertexBufferLayout& layout);
};