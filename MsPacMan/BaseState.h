#pragma once
#include <memory>
class BaseState
{
public:
	BaseState() = default;
	virtual ~BaseState() = default;
	BaseState(const BaseState& other) = delete;
	BaseState(BaseState&& other) = delete;
	BaseState& operator=(const BaseState& other) = delete;
	BaseState& operator=(BaseState&& other) = delete;

	virtual std::unique_ptr<BaseState> Update(float deltaTime) = 0;
	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;
};

