#pragma once
//#include <SDL_keyboard.h>
//#include <SDL_scancode.h>
//#include <vector>
#include "KeyBoardImpl.h"

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

		bool IsButtonDown(SDL_Scancode button)const { return m_pKeyBoardImpl->IsButtonDown(button); }
		bool IsButtonReleased(SDL_Scancode button)const {  return m_pKeyBoardImpl->IsButtonReleased(button); }
		bool IsButtonPressed(SDL_Scancode button)const { return m_pKeyBoardImpl->IsButtonPressed(button); }
	private:
		//std::vector<Uint8> m_Down;
		//std::vector<Uint8> m_Up;
		//std::vector<Uint8> m_Pressed;
		//std::vector<Uint8> m_PreviousState;

		std::unique_ptr<KeyBoardImpl> m_pKeyBoardImpl;

	};
}


