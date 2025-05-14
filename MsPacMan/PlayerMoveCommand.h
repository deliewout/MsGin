#pragma once
#include <memory>
#include <Command.h>
#include <GameObject.h>

class PlayerMoveCommand final : public Command
{
public:
	PlayerMoveCommand(std::shared_ptr<dae::GameObject> pPlayer, const glm::vec2& direction, float speed);

	~PlayerMoveCommand() = default;
	PlayerMoveCommand(const PlayerMoveCommand& other) = delete;
	PlayerMoveCommand(PlayerMoveCommand&& other) = delete;
	PlayerMoveCommand& operator=(const PlayerMoveCommand& other) = delete;
	PlayerMoveCommand& operator=(PlayerMoveCommand&& other) = delete;

	virtual void Execute() override;
private:
	std::shared_ptr<dae::GameObject> m_pPlayer;
	const glm::vec2 m_Direction;
	float m_Speed;
};

