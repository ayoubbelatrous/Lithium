#pragma once
#include "../Lithium.h"
#include <entt.hpp>

class Entity;
class Scene
{
	
private:
	entt::registry _registry;

public:
	Scene();
	~Scene();
	void onUpdate(double ts);
	Entity CreateEntity();

	friend class Entity;
};