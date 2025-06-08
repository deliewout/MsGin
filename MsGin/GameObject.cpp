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
	for (const auto& component : m_pComponents)
	{
		component->Update(deltaTime);
	}

	for (const auto& child : m_pChildren)
	{
		child->Update(deltaTime);
	}
}

void dae::GameObject::FixedUpdate(float fixedTimeStep)
{
	for (const auto& component : m_pComponents)
	{
		component->FixedUpdate(fixedTimeStep);
	}

	for (const auto& child : m_pChildren)
	{
		child->FixedUpdate(fixedTimeStep);
	}
}

void dae::GameObject::Render() const
{
	for (const auto& component : m_pComponents)
	{
		component->Render();
	}
	//const auto& pos = m_transform->GetPosition();
	//Renderer::GetInstance().RenderTexture(*m_texture, pos.x, pos.y);
}

void dae::GameObject::OnGui()
{
	for (const auto& component : m_pComponents)
	{
		component->OnGui();
	}
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
		m_transform->SetDirtyFlag();
	}
	if (m_pParent) m_pParent->RemoveChild(this);
	m_pParent = parent;
	if (m_pParent) m_pParent->AddChild(this);
}

//add a child to the end of the children list
void dae::GameObject::AddChild(GameObject* child)
{
	m_pChildren.emplace_back(child);
}
//remove a child from the list
void dae::GameObject::RemoveChild(GameObject* child)
{
	m_pChildren.erase(std::remove(m_pChildren.begin(), m_pChildren.end(), child), m_pChildren.end());
	child->m_pParent = nullptr;
}
