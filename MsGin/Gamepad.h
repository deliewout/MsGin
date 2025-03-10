#pragma once
#include <Windows.h>
#include <WinBase.h>
#include <Xinput.h>
class Gamepad
{
public:
	Gamepad(const int controllerIndex) :m_ControllerIndex(controllerIndex){}
	~Gamepad() = default;
	Gamepad(const Gamepad& other) = delete;
	Gamepad(Gamepad&& other) = delete;
	Gamepad& operator=(const Gamepad& other) = delete;
	Gamepad& operator=(Gamepad&& other) = delete;

	void ProcessGamepadInput();
	bool IsButtonDown(unsigned int button)const;
	bool IsButtonUp(unsigned int button)const;
	bool IsButtonPressed(unsigned int button)const;

private:
	int m_ControllerIndex{};
	int m_ButtonChanges;
	int m_ButtonPressedThisFrame;
	int m_ButtonReleasedThisFrame;

	XINPUT_STATE m_CurrentState{};
	XINPUT_STATE m_PrevState{};
};

