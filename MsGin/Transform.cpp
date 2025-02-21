#include "Transform.h"

void dae::Transform::SetPosition(const float x, const float y)
{
	m_position.x = x;
	m_position.y = y;
}

void dae::Transform::SetLocalPos(const float x, const float y)
{
	SetLocalPos({ x,y });
}

void dae::Transform::SetLocalPos(const glm::vec2& pos)
{
	m_LocalPos = pos;
}

void dae::Transform::Update(float )
{
}

void dae::Transform::FixedUpdate(float)
{
}
