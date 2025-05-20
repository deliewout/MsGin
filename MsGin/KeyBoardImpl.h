#pragma once

#include <SDL_keyboard.h>
#include <SDL_scancode.h>
#include <iostream>
#include <vector>

namespace dae
{
	class KeyBoardImpl
	{
	public:
		KeyBoardImpl();

		~KeyBoardImpl() = default;
		KeyBoardImpl(const KeyBoardImpl& other) = delete;
		KeyBoardImpl(KeyBoardImpl&& other) = delete;
		KeyBoardImpl& operator=(const KeyBoardImpl& other) = delete;
		KeyBoardImpl& operator=(KeyBoardImpl&& other) = delete;


		void Update();

		bool IsButtonDown(SDL_Scancode button)const { return m_Down[button]; }
		bool IsButtonReleased(SDL_Scancode button)const { return m_Up[button]; }
		bool IsButtonPressed(SDL_Scancode button)const { return m_Pressed[button]; }
	private:
		std::vector<Uint8> m_Down;
		std::vector<Uint8> m_Up;
		std::vector<Uint8> m_Pressed;
		std::vector<Uint8> m_PreviousState;

	};
}

