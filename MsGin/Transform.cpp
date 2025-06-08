#include "Transform.h"

#include "GameObject.h"
#include <iostream>

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

void dae::Transform::SetLocalPos(const float x, const float y)
{
	SetLocalPos({ x,y });
}

void dae::Transform::SetLocalPos(const glm::vec2& pos)
{
	m_LocalPos = pos;
	SetDirtyFlag();
}

void dae::Transform::SetWorldScale(const float x, const float y)
{
	SetWorldScale({ x,y });
}

void dae::Transform::SetWorldScale(const glm::vec2& scale)
{
	auto parentScale = m_pParent ? m_pParent->GetTransform()->GetWorldScale() : glm::vec2{ 2.f, 2.f };
	m_localScale = scale / parentScale;
	SetDirtyFlag();
}

const glm::vec2& dae::Transform::GetWorldScale()
{
	if (m_PosDirty)
		UpdateWorldScale();
	return m_WorldScale;
}

void dae::Transform::SetLocalScale(float x, float y)
{
	SetLocalScale({ x,y });
}

void dae::Transform::SetLocalScale(const glm::vec2& scale)
{
	m_localScale = scale;
	SetDirtyFlag();
}

void dae::Transform::UpdateWorldScale()
{
	if (m_PosDirty)
	{
	if (m_pParent == nullptr)
		m_WorldScale = m_localScale;
	else
		m_WorldScale = m_localScale * m_pParent->GetTransform()->GetWorldScale();
	m_PosDirty = false;
	}
	
}

void dae::Transform::MoveLocalPosition(const glm::vec2& Pos)
{
	m_LocalPos += Pos;
	std::cout << m_LocalPos.x << " " << m_LocalPos.y << std::endl;
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
