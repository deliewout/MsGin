#pragma once
#include "Component.h"
#include "Subject.h"
#include <memory>

class HealthComponent : public dae::Component, dae::Subject
{
public:
	HealthComponent(dae::GameObject* pOwner, int lives) :Component(pOwner),m_Lives(lives){}
	~HealthComponent() = default;
	HealthComponent(const HealthComponent& other) = delete;
	HealthComponent(HealthComponent&& other) = delete;
	HealthComponent& operator=(const HealthComponent& other) = delete;
	HealthComponent& operator=(HealthComponent&& other) = delete;


	void RemoveHealth(int lives);
	void IsOutOfLives();

private:
	int m_Lives;
	std::unique_ptr<dae::Subject> m_Subject;
};




