#pragma once
#include "BaseState.h"
#include <GameObject.h>

class StartState final: public BaseState
{
public:
	StartState(dae::GameObject* pOwner);

	virtual ~StartState()=default;
	StartState(const StartState& other) = delete;
	StartState(StartState&& other) = delete;
	StartState& operator=(const StartState& other) = delete;
	StartState& operator=(StartState&& other) = delete;

	virtual std::unique_ptr<BaseState> Update(float delaTime);
	virtual void OnEnter();
	virtual void OnExit();

private:
	dae::GameObject* m_pOwner{};

	float m_Timer{0.0f};
	float m_TimeToSpawn{ 5.0f };


};

class WanderState final: public BaseState
{
public:
	WanderState(dae::GameObject* pOwner);

	virtual std::unique_ptr<BaseState> Update(float delaTime);
	virtual void OnEnter();
	virtual void OnExit();

private:
	dae::GameObject* m_pOwner{};
};

class ChasingState final: public BaseState
{

public:
	ChasingState(dae::GameObject* pOwner);

	virtual std::unique_ptr<BaseState> Update(float delaTime);
	virtual void OnEnter();
	virtual void OnExit();

private:
	dae::GameObject* m_pOwner{};
};

class RespawnState final : public BaseState
{
public:
	RespawnState(dae::GameObject* pOwner);

	virtual std::unique_ptr<BaseState> Update(float delaTime);
	virtual void OnEnter();
	virtual void OnExit();

private:
	dae::GameObject* m_pOwner{};
};

class DeadState final : public BaseState
{
public:
	DeadState(dae::GameObject* pOwner);

	virtual std::unique_ptr<BaseState> Update(float delaTime);
	virtual void OnEnter();
	virtual void OnExit();

private:
	dae::GameObject* m_pOwner{};
};


