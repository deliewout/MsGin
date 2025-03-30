#pragma once
#include "Component.h"

namespace dae
{
	class TextObject;
	class FPSComponent : public Component
	{
	public:
		FPSComponent(GameObject* pOwner);
		~FPSComponent() = default;
		FPSComponent(const FPSComponent& other) = delete;
		FPSComponent(FPSComponent&& other) = delete;
		FPSComponent& operator=(const FPSComponent& other) = delete;
		FPSComponent& operator=(FPSComponent&& other) = delete;

		void Update(float deltaTime) override;
	private:
		TextObject* m_pTextComponent{};
		float m_AccumulatedSec{};
		float m_UpdateInterval{0.2f};
	};
}


