#include "VertexBuffer.h"
#include "Renderer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
	
	GLCall(glGenBuffers(1, &_id));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, _id));
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::VertexBuffer()
{
	_id = 0;
}

void VertexBuffer::Bind() const
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, _id));
}
void VertexBuffer::UnBind() const
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
VertexBuffer::~VertexBuffer()
{
	GLCall(glDeleteBuffers(1, &_id));
}
