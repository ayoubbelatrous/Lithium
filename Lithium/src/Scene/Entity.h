#pragma once
#include "Scene.h"


class Entity{
private:
	entt::entity _handle;
public:
	Entity() = default;
	Entity(const entt::entity& handle, Scene* scene);
	Entity(const Entity& other) = default;
	
	Scene* _scene;

	//helper function
	template <typename T>
	bool HasComponent()
	{
		return _scene->_registry.any_of<T>(_handle);
	}
	template <typename T>
	T& GetComponent()
	{
		return _scene->_registry.get<T>(_handle);
	}
	template <typename T>
	void RemoveComponent()
	{
		_scene->_registry.remove<T>(_handle);

	}
	template <typename T,typename... Args>
	void AddComponent(Args&&... args)
	{
		_scene->_registry.emplace<T>(_handle,std::forward<Args>(args)...);
	}



	operator uint32_t() const { return (uint32_t)_handle; }

	bool operator==(const Entity& other) const
	{
		return _handle == other._handle;
	}

	bool operator!=(const Entity& other) const
	{
		return !(*this == other);
	}
};