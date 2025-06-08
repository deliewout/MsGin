#pragma once
#include <string>
#include <memory>
#include "GameObject.h"
#include "Component.h"
#include "Transform.h"
#include "RenderComponent.h"

namespace dae
{
	class Font;
	class Texture2D;
	class TextObject final :public Component
	{
	public:
		void Update(float deltaTime) override;
		void FixedUpdate(float fixedTimeStep) override;
		void Render() const override;

		void SetText(const std::string& text);
		void SetFont(std::shared_ptr<Font> font);
		void SetPosition(float x, float y);

		//TextObject(const std::string& text, std::shared_ptr<Font> font);
		TextObject(GameObject* pOwner);
		virtual ~TextObject() = default;
		TextObject(const TextObject& other) = delete;
		TextObject(TextObject&& other) = delete;
		TextObject& operator=(const TextObject& other) = delete;
		TextObject& operator=(TextObject&& other) = delete;

	private:
		bool m_needsUpdate;
		std::string m_text;
		std::shared_ptr<Transform> m_transform{};
		std::shared_ptr<Font> m_font;
		std::shared_ptr<Texture2D> m_textTexture;
		std::shared_ptr<RenderComponent> m_pOwner{ GetOwner()->GetComponent<dae::RenderComponent>() };

	};
}
