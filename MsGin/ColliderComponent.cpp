#include "ColliderComponent.h"

dae::ColliderComponent::ColliderComponent(GameObject* pOwner,std::string tag)
	:Component{pOwner},m_Tag{tag}
{
	m_Colliders.push_back(this);
}

dae::ColliderComponent::~ColliderComponent()
{
	auto it = std::find(m_Colliders.begin(), m_Colliders.end(), this);
	if (it != m_Colliders.end())
		m_Colliders.erase(it);
}

void dae::ColliderComponent::Update(float)
{
}

bool dae::ColliderComponent::IsColliding( const std::string& ignoreTag) const
{
	for (auto* other : m_Colliders)
	{
		if (other == this || other->m_Tag == ignoreTag)
			continue;
		if (SDL_HasIntersection(&m_Collider, &other->m_Collider))
			return true;
	}
	return false;
}
