#include "Gamepad.h"

void Gamepad::BindGamepad()
{

	CopyMemory(&m_PrevState, &m_CurrentState, sizeof(XINPUT_STATE));
	ZeroMemory(&m_CurrentState, sizeof(XINPUT_STATE));
	DWORD dwResult = XInputGetState(m_ControllerIndex, &m_CurrentState);
	if (dwResult== ERROR_DEVICE_NOT_CONNECTED)
	{
		return;
	}

	m_ButtonChanges = m_CurrentState.Gamepad.wButtons ^ m_PrevState.Gamepad.wButtons;
	m_ButtonPressedThisFrame = m_ButtonChanges & m_CurrentState.Gamepad.wButtons;
	m_ButtonReleasedThisFrame = m_ButtonChanges & (~m_CurrentState.Gamepad.wButtons);
}

bool Gamepad::IsButtonDown(unsigned int button) const
{
	return m_ButtonPressedThisFrame & button;
}

bool Gamepad::IsButtonUp(unsigned int button) const
{
	return m_ButtonReleasedThisFrame & button;
}

bool Gamepad::IsButtonPressed(unsigned int button) const
{
	return m_CurrentState.Gamepad.wButtons & button;
}

