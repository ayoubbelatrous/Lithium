#pragma once
#include "Renderer.h"
#include <string>
class Texture
{
private:
	unsigned int _id;
	unsigned char* _localBuffer;
	int _width;
	int _height;
	int _BPP;
public:
	Texture(const std::string& path);
	Texture(int width, int height, int channels,int colormode, int colormode2);
	Texture(){}
	~Texture();
	void Bind() const;
	void UnBind() const;
	unsigned int GetID() const;

};