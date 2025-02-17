#include "FPSComponent.h"
#include "sstream"
#include "GameObject.h"
#include "TextObject.h"

void dae::FPSComponent::Update(float deltaTime)
{
	if (!m_pTextComponent)
	{
		m_pTextComponent=GetOwner()->GetComponent<TextObject>();
	}
	m_AccumulatedSec += deltaTime;
	if (m_AccumulatedSec>=m_UpdateInterval)
	{
		m_AccumulatedSec -= m_UpdateInterval;

		std::stringstream fps{ std::to_string(static_cast<int>(1.0f / deltaTime)) };
		fps << " FPS";
		m_pTextComponent->SetText(fps.str());
	}
}
