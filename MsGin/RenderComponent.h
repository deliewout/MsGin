#pragma once
#include <memory>

#include "Component.h"
#include <string>

namespace dae
{
	class Texture2D;
	class RenderComponent final: public Component
	{
	public:
		RenderComponent(GameObject* pOwner):Component(pOwner) {}
		virtual ~RenderComponent()=default;
		RenderComponent(const RenderComponent& other) = delete;
		RenderComponent& operator=(const RenderComponent& rhs) = delete;
		RenderComponent(RenderComponent&& other) = delete;
		RenderComponent& operator=(RenderComponent&& rhs) = delete;

		void Render(glm::vec2 pos) const override;

		void Settexture(std::shared_ptr<Texture2D> pTexture) { m_pTexture = pTexture; }

	private:
		std::shared_ptr<Texture2D> m_pTexture;

	};
}


