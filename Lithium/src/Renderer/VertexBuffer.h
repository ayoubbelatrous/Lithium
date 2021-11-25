#pragma once
class VertexBuffer
{
private:
	unsigned int _id;
public:

	VertexBuffer(const void* data,unsigned int size);
	VertexBuffer();
	~VertexBuffer();
	void Bind() const;
	void UnBind() const;
};