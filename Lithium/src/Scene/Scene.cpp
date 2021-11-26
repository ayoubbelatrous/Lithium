#include "Scene.h"
#include "Entity.h"



Scene::Scene()
{

	
}

void Scene::onUpdate(double ts)
{
	
}



Entity Scene::CreateEntity()
{
	return { _registry.create(),this };
}

Scene::~Scene()
{
	
}

entt::registry& Scene::GetReg()
{
	return _registry;
}
