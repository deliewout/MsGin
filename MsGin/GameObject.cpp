#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"

dae::GameObject::GameObject()
{
	AddComponent<Transform>();
}

dae::GameObject::~GameObject()
{
	m_RemovedGameObject = true;
}

void dae::GameObject::Update(float deltaTime)
{
	for (auto& component : m_pComponents)
	{
		component->Update(deltaTime);
	}
}

void dae::GameObject::FixedUpdate(float fixedTimeStep)
{
	for (auto& component : m_pComponents)
	{
		component->FixedUpdate(fixedTimeStep);
	}
}

void dae::GameObject::Render() const
{
	for (auto& component : m_pComponents)
	{
		component->Render();
	}
	//const auto& pos = m_transform->GetPosition();
	//Renderer::GetInstance().RenderTexture(*m_texture, pos.x, pos.y);
}

void dae::GameObject::SetTexture(const std::string& filename)
{
	//m_texture = ResourceManager::GetInstance().LoadTexture(filename);
	filename;
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_transform->SetPosition(x, y);
}

void dae::GameObject::SetParent(GameObject* parent, bool keepWorldPos)
{
	if (m_pParent==this||m_pParent==parent)
		return;
	if (parent == nullptr)
		m_transform->SetLocalPos(m_transform->GetWorldPosition());
	else
	{
		if (keepWorldPos)
			m_transform->SetLocalPos(m_transform->GetWorldPosition() - parent->m_transform->GetWorldPosition());
	}
	if (m_pParent) m_pParent->RemoveChild(this);
	m_pParent = parent;
	if (m_pParent) m_pParent->AddChild(this);
}

void dae::GameObject::AddChild(GameObject* child)
{
	m_pChildren.emplace_back(child);
}

void dae::GameObject::RemoveChild(GameObject* child)
{
	m_pChildren.erase(std::remove(m_pChildren.begin(), m_pChildren.end(), child), m_pChildren.end());
}
