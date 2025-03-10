#include "KeyBoard.h"

dae::KeyBoard::KeyBoard()
{
    m_Down.resize(SDL_NUM_SCANCODES);
    m_Up.resize(SDL_NUM_SCANCODES);
    m_Pressed.resize(SDL_NUM_SCANCODES);
    m_PreviousState.resize(SDL_NUM_SCANCODES);
}

void dae::KeyBoard::Update()
{
	std::vector<Uint8> currenState(SDL_NUM_SCANCODES);

	auto keyboardState = SDL_GetKeyboardState(nullptr);

	for (size_t i{}; i < currenState.size(); ++i)
	{
		currenState[i] = keyboardState[i];
	}

	for (size_t i{}; i < currenState.size(); ++i)
	{
		m_Down[i] = (currenState[i] & ~m_PreviousState[i]);
		m_Up[i] = (~currenState[i] & m_PreviousState[i]);
		m_Pressed[i] = currenState[i];
	}
	m_PreviousState = currenState;

}
