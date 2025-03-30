#include "FPSComponent.h"

#include <iomanip>

#include "sstream"
#include "GameObject.h"
#include "TextObject.h"

dae::FPSComponent::FPSComponent(GameObject* pOwner)
	:Component(pOwner)
{
	if (!m_pTextComponent)
	{
		m_pTextComponent = GetOwner()->GetComponent<TextObject>();
	}
}

void dae::FPSComponent::Update(float deltaTime)
{

	m_AccumulatedSec += deltaTime;
	if (m_AccumulatedSec>=m_UpdateInterval)
	{
		m_AccumulatedSec -= m_UpdateInterval;

		std::stringstream fps{  };
		fps<< std::to_string(1.0f / deltaTime) << " FPS";
		m_pTextComponent->SetText(fps.str());
	}
}
