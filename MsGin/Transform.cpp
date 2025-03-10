#include "Transform.h"

#include "GameObject.h"

const glm::vec2& dae::Transform::GetWorldPosition()
{
	if (m_PosDirty)
		UpdateWorldPos();
	return m_WorldPos;
}

void dae::Transform::UpdateWorldPos()
{
	if (m_PosDirty)
	{
		if (m_pParent == nullptr)
			m_WorldPos = m_LocalPos;
		else
			m_WorldPos = GetWorldPosition() + m_LocalPos;
	}
	m_PosDirty = false;
}

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
	SetDirtyFlag();
}
void dae::Transform::MoveLocalPosition(const glm::vec2& Pos)
{
	m_LocalPos += Pos;
	SetDirtyFlag();
}
void dae::Transform::SetDirtyFlag()
{
	m_PosDirty = true;
	for (auto& child:GetOwner()->GetChildren())
	{
		child->GetTransform()->SetDirtyFlag();
	}
}

void dae::Transform::Update(float )
{
}

void dae::Transform::FixedUpdate(float)
{
}
