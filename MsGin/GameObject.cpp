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
	m_transform->SetPosition(x, y, 0.0f);
}
