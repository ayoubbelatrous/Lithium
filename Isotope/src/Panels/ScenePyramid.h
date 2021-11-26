#pragma once
#include "Scene/Scene.h"
#include "Scene/Entity.h"

class ScenePyramid
{
public:
	void Init(Lithium::Ref<Scene> scene);
	void RenderUI();
	void DrawEntity(Entity entity);
	Entity selection;
private:
	Lithium::Ref<Scene> _context;
	
};

