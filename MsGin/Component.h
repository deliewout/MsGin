﻿#pragma once
#include <glm.hpp>
//#include "GameObject.h"

namespace dae
{
	class GameObject;
	class Component
	{
	public:

		virtual void Update(float deltaTime);
		virtual void FixedUpdate(float fixedTimeStep);
		virtual void Render(glm::vec2 ) const {}
		virtual void OnGui(){}

		virtual ~Component() = default;
		Component(const Component& other) = delete;
		Component(Component&& other) = delete;
		Component& operator=(const Component& other) = delete;
		Component& operator=(Component&& other) = delete;

		GameObject* GetOwner() const { return m_pOwner; }

	protected:
		Component(GameObject* pOwner) : m_pOwner{pOwner} {}
	private:
		GameObject* m_pOwner;
	};
}
