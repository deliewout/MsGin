#pragma once
#include <memory>
#include <vector>
#include "Transform.h"
#include "component.h"

namespace dae
{
	class Texture2D;

	
	class GameObject final
	{
	public:
		void Update(float deltaTime);
		void FixedUpdate(float fixedTimeStep);
		void Render() const;

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);

		GameObject();
		~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		template<typename T>
		T* AddComponent();
		template<typename T>
		void removeComponent();
		template<typename T>
		T* GetComponent();
		template<typename T>
		bool HasComponent();

		void SetParent(GameObject* parent, bool keepWorldPos);

		GameObject* GetParent() const { return m_pParent; }
		size_t GetChildCount() const { return m_pChildren.size(); }
		GameObject* GetChildAt(unsigned int index) const { return m_pChildren[index]; }

		bool IsDestroyed() const { return m_RemovedGameObject; }
	private:
		std::unique_ptr<Transform> m_transform{};
		// todo: mmm, every gameobject has a texture? Is that correct?
		//std::shared_ptr<Texture2D> m_texture{};

		std::vector<std::unique_ptr<Component>> m_pComponents;
		GameObject* m_pParent;
		std::vector<GameObject*> m_pChildren;

		bool m_RemovedGameObject{false};
		void AddChild(GameObject* child);
		void RemoveChild(GameObject* child);

	};

	template<typename T>
	T* GameObject::AddComponent()
	{
		//make sure the gameObject doesn't have a component like this in its components vector
		if (HasComponent<T>() == false)
		{
			auto pComponent = std::make_unique<T>(this);
			T* pComponentPtr{ pComponent.get() };
			if constexpr (std::is_same<T, Transform>())
			{
				m_transform = std::move(pComponent);
			}
			else
			{
				m_pComponents.emplace_back(std::move(pComponent));
			}


			return  pComponentPtr;
		}

		return nullptr;
	}

	template<typename T>
	void GameObject::removeComponent()
	{
		for (auto it = m_pComponents.begin(); it != m_pComponents.end(); ++it)
		{
			if(dynamic_cast<T*>(it->get()))
			{
				m_pComponents.erase(it);
				break;
			}
		}
	}

	template<typename T>
	T* GameObject::GetComponent()
	{
		for (const auto& component : m_pComponents)
		{
			if (auto correctComponent = dynamic_cast<T*>(component.get()))
			{
				return correctComponent;
			}
		}
		return nullptr;
	}

	template<typename T>
	bool GameObject::HasComponent()
	{
		return GetComponent<T>() != nullptr;
	}
}
