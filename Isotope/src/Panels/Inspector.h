#pragma once
#pragma once
#include "Scene/Scene.h"
#include "Scene/Entity.h"
#include <imgui/imgui_internal.h>
#include "imgui/imgui.h"


class Inspector
{
public:
	void Init(Lithium::Ref<Scene> scene);
	void RenderUI();
	void DrawComponent(Entity entity);
	void SetSelection(Entity entity);
	Entity selection;
private:
	Lithium::Ref<Scene> _context;

};

