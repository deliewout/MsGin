#include "RenderComponent.h"

#include "Renderer.h"

void dae::RenderComponent::Render(glm::vec2 pos) const
{
	Renderer::GetInstance().RenderTexture(*m_pTexture, pos.x, pos.y);
}
