#pragma once
#include "Component.h"

namespace dae
{
	class HealthComponent : public Component
	{
	public:
		HealthComponent(GameObject* pOwner) :Component(pOwner){}
		~HealthComponent() = default;
		HealthComponent(const HealthComponent& other) = delete;
		HealthComponent(HealthComponent&& other) = delete;
		HealthComponent& operator=(const HealthComponent& other) = delete;
		HealthComponent& operator=(HealthComponent&& other) = delete;
	};
}


