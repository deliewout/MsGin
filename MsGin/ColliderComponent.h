#pragma once
#include "Component.h"
#include <SDL.h>
#include <string>
#include <vector>

namespace dae
{
	class ColliderComponent: public Component
	{
	public:
		ColliderComponent(GameObject* pOwner, std::string tag);

		virtual ~ColliderComponent();
		ColliderComponent(const ColliderComponent& other) = delete;
		ColliderComponent(ColliderComponent&& other) = delete;
		ColliderComponent& operator=(const ColliderComponent& other) = delete;
		ColliderComponent& operator=(ColliderComponent&& other) = delete;

		virtual void Update(float deltaTime)override;

		bool IsColliding( const std::string& ignoreTag) const;

	private:
		SDL_Rect m_Collider;
		std::string m_Tag;

		static std::vector<ColliderComponent*> m_Colliders;
	};

}
