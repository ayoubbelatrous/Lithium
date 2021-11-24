#pragma once
#include <GL/glew.h>
#include <iostream>
#include "Shader.h"
#include <memory>
#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Texture.h"
#include "imgui/imgui.h"
#include "glm/glm.hpp"
#include <glm/gtc/type_ptr.hpp>
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/matrix_decompose.hpp"
#include "FrameBuffer.h"
#include "glfw3.h"
class Application
{

public:
	float color = 0;
	Shader* hi = new Shader;
	VertexBuffer* vb;
	IndexBuffer* ib;
	Texture* tex = new Texture;
	FrameBuffer* fb;
	glm::vec3 pos;
	glm::vec3 rot;
	glm::vec3 sca;
	glm::mat4 proj;
	float orthosize;
	glm::vec4 background;
	ImVec4 windBG;
	glm::vec2 prev;
	glm::vec2 m_ViewportBounds[2];
	glm::vec2 viewportSize;
	void Init();
	void Render();
	void UIRender();
	void Delete();
	float scrollX;
	float scrollY;
	void SetScroll(float x,float y)
	{
		scrollY = y;
		scrollX = x;
	}
	float i;
	

	glm::mat4 model;
	glm::mat4 view;
	bool draw;
	glm::mat4 matrix;

	float mouse[2];

	bool move;
	

};



