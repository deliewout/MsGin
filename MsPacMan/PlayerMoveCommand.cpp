#include "PlayerMoveCommand.h"

PlayerMoveCommand::PlayerMoveCommand(std::shared_ptr<dae::GameObject> pPlayer, const glm::vec2& direction, float speed)
	:m_pPlayer{ std::move(pPlayer) }, m_Direction{ direction }, m_Speed{ speed }
{

}

void PlayerMoveCommand::Execute()
{
	m_pPlayer->GetTransform()->MoveLocalPosition(m_Direction * m_Speed);
}