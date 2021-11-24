#include "Transform.h"

Transform::Transform(const glm::vec3& pos)
{
	this->position = pos;
	rotation = glm::vec3(0);
	scale = glm::vec3(1);
}

Transform::Transform()
{
	position = glm::vec3(0);
	rotation = glm::vec3(0);
	scale = glm::vec3(1);
}

Transform::~Transform()
{

}

glm::mat4 Transform::getMatrix()
{
	return glm::translate(glm::mat4(1.0f), position);
}

