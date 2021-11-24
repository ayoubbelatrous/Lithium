#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"


class Transform
{
public:
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
	Transform(const glm::vec3& pos);
	Transform();
	~Transform();
	glm::mat4 getMatrix();
};