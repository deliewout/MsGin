#include "RenderComponent.h"

#include "Renderer.h"
#include "GameObject.h"
#include "Texture2D.h"

void dae::RenderComponent::Render() const
{
	auto pos = GetOwner()->GetTransform()->GetWorldPosition();
	auto scale = GetOwner()->GetTransform()->GetWorldScale();
	

	int texW = 0, texH = 0;
	SDL_QueryTexture(m_pTexture->GetSDLTexture(), nullptr, nullptr, &texW, &texH);

	Renderer::GetInstance().RenderTexture(*m_pTexture, pos.x, pos.y, texW * scale.x, texH * scale.y);
}
