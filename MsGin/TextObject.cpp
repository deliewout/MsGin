#include <stdexcept>
#include <SDL_ttf.h>
#include "TextObject.h"
#include "Renderer.h"
#include "Font.h"
#include "Texture2D.h"

//dae::TextObject::TextObject(const std::string& text, std::shared_ptr<Font> font) 
//	: m_needsUpdate(true), m_text(text), m_font(std::move(font)), m_textTexture(nullptr)
//{ }

dae::TextObject::TextObject(GameObject* pOwner)
	:Component{pOwner}, m_needsUpdate(true), m_transform(GetOwner()->GetComponent<dae::Transform>())
{
}

void dae::TextObject::Update(float)
{
	if (m_needsUpdate)
	{
		const SDL_Color color = { 255,255,255,255 }; // only white text is supported now
		const auto surf = TTF_RenderText_Blended(m_font->GetFont(), m_text.c_str(), color);
		if (surf == nullptr) 
		{
			throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
		}
		auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);
		if (texture == nullptr) 
		{
			throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
		}
		SDL_FreeSurface(surf);
		m_textTexture = std::make_shared<Texture2D>(texture);
		m_needsUpdate = false;
	}
}

void dae::TextObject::FixedUpdate(float)
{
}

void dae::TextObject::Render() const
{
	if (m_textTexture != nullptr)
	{
		//const auto& pos = m_transform->GetPosition();
		auto pos = GetOwner()->GetTransform()->GetWorldPosition();
		auto scale = GetOwner()->GetTransform()->GetWorldScale();
		int texW = 0, texH = 0;
		SDL_QueryTexture(m_textTexture->GetSDLTexture(), nullptr, nullptr, &texW, &texH);

		Renderer::GetInstance().RenderTexture(*m_textTexture, pos.x, pos.y, texW * scale.x, texH * scale.y);
	}
}

// This implementation uses the "dirty flag" pattern
void dae::TextObject::SetText(const std::string& text)
{
	m_text = text;
	m_needsUpdate = true;
}

void dae::TextObject::SetFont(std::shared_ptr<Font> font)
{
	m_font = font;
}

void dae::TextObject::SetPosition(const float x, const float y)
{
	m_transform->SetLocalPos(x, y);
}




