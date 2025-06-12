#include "EnemyStates.h"
#include <random>
#include <ResourceManager.h>
#include <RenderComponent.h>

StartState::StartState(dae::GameObject* pOwner)
	:m_pOwner{ pOwner }
{
}

std::unique_ptr<BaseState> StartState::Update(float delaTime)
{
	m_Timer += delaTime;
	if (m_Timer >= m_TimeToSpawn)
	{
		return std::make_unique<WanderState>(m_pOwner);
	}
	return nullptr;
}



void StartState::OnEnter()
{

	const auto& pTexture{ dae::ResourceManager::GetInstance().LoadTexture("Sprites/enemies/sidesBlue.jpg") };
	m_pOwner->GetComponent<dae::RenderComponent>()->Settexture(pTexture);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dist(0.0f, 5.0f);
	m_TimeToSpawn = dist(gen);
}

void StartState::OnExit()
{
}

WanderState::WanderState(dae::GameObject* pOwner)
	:m_pOwner{pOwner}
{
}
std::unique_ptr<BaseState> WanderState::Update(float )
{

}
void WanderState::OnEnter()
{

}
void WanderState::OnExit()
{
}
ChasingState::ChasingState(dae::GameObject* )
{
}
std::unique_ptr<BaseState> ChasingState::Update(float )
{

}
void ChasingState::OnEnter()
{

}
void ChasingState::OnExit()
{
}
RespawnState::RespawnState(dae::GameObject* )
{
}
std::unique_ptr<BaseState> RespawnState::Update(float )
{

}
void RespawnState::OnEnter()
{

}
void RespawnState::OnExit()
{
}
DeadState::DeadState(dae::GameObject*)
{
}
std::unique_ptr<BaseState> DeadState::Update(float)
{

}
void DeadState::OnEnter()
{

}
void DeadState::OnExit()
{

}