#pragma once
#include <glm.hpp>

#include "Component.h"

namespace dae
{
	class gameObject;
	class Transform final : public Component
	{
	public:
		Transform(GameObject* pOwner) : Component(pOwner) {}

		~Transform() = default;
		Transform(const Transform& other) = delete;
		Transform& operator=(const Transform& rhs) = delete;
		Transform(Transform&& other) = delete;
		Transform& operator=(Transform&& rhs) = delete;

		void Update(float deltaTime);
		void FixedUpdate(float fixedTimeStep);
		void Render() const {}

		const glm::vec2& GetLocalPosition() const { return m_LocalPos; }
		const glm::vec2& GetWorldPosition();
		void UpdateWorldPos();

		void SetPosition(float x, float y);
		void SetLocalPos(const float x, const float y);
		void SetLocalPos(const glm::vec2& pos);

		void MoveLocalPosition(const glm::vec2& Pos);

		void SetDirtyFlag();

		void SetParent(GameObject* pParent) { m_pParent = pParent; }
		
	private:
		glm::vec2 m_position{};
		glm::vec2 m_LocalPos{};
		glm::vec2 m_WorldPos{};

		bool m_PosDirty{false};
		GameObject* m_pParent{};
	};
}
