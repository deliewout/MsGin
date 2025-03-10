#pragma once
#include <SDL_keyboard.h>
#include <SDL_scancode.h>
#include <vector>

namespace dae
{
	class KeyBoard
	{
	public:
		KeyBoard();

		~KeyBoard() = default;
		KeyBoard(const KeyBoard& other) = delete;
		KeyBoard(KeyBoard&& other) = delete;
		KeyBoard& operator=(const KeyBoard& other) = delete;
		KeyBoard& operator=(KeyBoard&& other) = delete;


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


