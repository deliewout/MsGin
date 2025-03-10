#include "Command.h"

void PlayerMoveCommand::Execute()
{
	m_pPlayer->GetTransform()->MoveLocalPosition(m_Direction * m_Speed);
}
