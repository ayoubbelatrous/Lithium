#pragma once
#include "../Lithium.h"

struct TransformComponent {

	glm::vec3 Position;
	glm::vec3 Rotation;
	glm::vec3 Scale = { 1,1,1 };
	TransformComponent() = default;
	TransformComponent(const TransformComponent&) = default;

	glm::mat4 GetMatrix() const
	{
		glm::mat4 rotation = glm::toMat4(glm::quat(Rotation));

		return glm::translate(glm::mat4(1.0f), Position)
			* rotation
			* glm::scale(glm::mat4(1.0f), Scale);
	}

};



struct TagComponent
{
	std::string Name = "Entity";
	TagComponent() = default;
	TagComponent(const TagComponent& other) = default;
	TagComponent(const std::string& name)
		:Name(name)
	{}
	std::string& GetName()
	{
		return Name;
	}
};


struct SpriteRendererComponent
{
	glm::vec4 Color;
	SpriteRendererComponent() = default;
	SpriteRendererComponent(const SpriteRendererComponent& other) = default;
	SpriteRendererComponent(const glm::vec4& color)
		:Color(color)
	{
	}

	glm::vec4 GetColor() const
	{
		return Color;
	}

};
