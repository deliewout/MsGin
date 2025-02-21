#pragma once
#include <glm.hpp>

#include "Component.h"

namespace dae
{
	class Transform final : public Component
	{
	public:
		Transform(GameObject* pOwner) : Component(pOwner) {}

		const glm::vec2& GetPosition() const { return m_position; }
		const glm::vec2& GetWorldPosition() const { return m_WorldPos; }

		void SetPosition(float x, float y);
		void SetLocalPos(const float x, const float y);
		void SetLocalPos(const glm::vec2& pos);
		

		void Update(float deltaTime);
		void FixedUpdate(float fixedTimeStep);
		void Render() const {}
	private:
		glm::vec2 m_position{};
		glm::vec2 m_LocalPos{};
		glm::vec2 m_WorldPos{};

		bool m_PosDirty{false};
	};
}
