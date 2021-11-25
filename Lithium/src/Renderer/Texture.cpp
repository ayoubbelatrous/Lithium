#include "Texture.h"
#include "../vendor/stb/stb_image.h"
Texture::Texture(const std::string& path)
{
	stbi_set_flip_vertically_on_load(1);
	_localBuffer = stbi_load(path.c_str(), &_width, &_height, &_BPP, 4);

	GLCall(glGenTextures(1, &_id));
	GLCall(glBindTexture(GL_TEXTURE_2D, _id));

	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
	GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _localBuffer));
	stbi_image_free(_localBuffer);
}

Texture::Texture(int width, int height, int channels,int colormode, int colormode2)
{
	_width = width;
	_height = height;
	_BPP = channels;
	_localBuffer = nullptr;
	GLCall(glGenTextures(1, &_id));
	GLCall(glBindTexture(GL_TEXTURE_2D, _id));

	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
	GLCall(glTexImage2D(GL_TEXTURE_2D, 0, colormode, _width, _height, 0, colormode2, GL_UNSIGNED_BYTE, NULL));

}

Texture::~Texture()
{
	GLCall(glDeleteTextures(1, &_id));
}

void Texture::Bind() const
{
	GLCall(glActiveTexture(GL_TEXTURE0));
	GLCall(glBindTexture(GL_TEXTURE_2D, _id));
}

void Texture::UnBind() const
{
	GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}

unsigned int Texture::GetID() const
{
	return _id;
}
