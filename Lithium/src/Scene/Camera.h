#pragma once
#include "../Components/Transform.h"

class Camera
{
private:
	Transform transform;
	int mode;
public:
	Camera(const glm::vec3& pos, int mode);
};