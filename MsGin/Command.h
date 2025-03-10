#pragma once
#include "GameObject.h"

class Command
{
public:
	virtual ~Command()=default;
	virtual void Execute() = 0;
};

class PlayerMoveCommand final: public Command
{
public:
	PlayerMoveCommand(std::shared_ptr<dae::GameObject> pPlayer, const glm::vec2& direction, float speed)
		:m_pPlayer{std::move(pPlayer)},m_Direction{direction},m_Speed{speed}
	{
		
	}
	void Execute() override;
private:
	std::shared_ptr<dae::GameObject> m_pPlayer;
	const glm::vec2& m_Direction;
	float m_Speed;
};

