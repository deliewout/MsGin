#pragma once
#include <glm.hpp>

#include "Component.h"

namespace dae
{
	class Transform final : public Component
	{
	public:
		Transform(GameObject* pOwner) : Component(pOwner) {}
		const glm::vec3& GetPosition() const { return m_position; }
		void SetPosition(float x, float y, float z);

		void Update(float deltaTime);
		void FixedUpdate(float fixedTimeStep);
		void Render() const {}
	private:
		glm::vec3 m_position{};


	};
}
