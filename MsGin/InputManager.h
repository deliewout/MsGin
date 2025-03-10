#pragma once
#include "Singleton.h"
#include <memory>
#include <vector>
#include "Command.h"
#include "Gamepad.h"
#include "KeyBoard.h"

namespace dae
{

	enum class GamepadButtons
	{
		Dpad_Up = 0x0001,
		Dpad_Down = 0x0002,
		Dpad_Left = 0x0004,
		Dpad_Right = 0x0008,
		Dpad_Start = 0x0010,
		Dpad_Back = 0x0020,
		//Dpad_LeftThumb = 0x0040,
		//Dpad_RightThumb = 0x0080,
		Dpad_LeftShoulder = 0x0100,
		Dpad_RightShoulder = 0x0200,
		Dpad_A = 0x1000,
		Dpad_B = 0x2000,
		Dpad_X = 0x4000,
		Dpad_Y = 0x8000
	};

	enum class KeyStates
	{
		up,
		down,
		pressed,
	};

	struct GamepadCommand final
	{

		GamepadCommand(const int& controllerIdx, const GamepadButtons& gamepadButtons,const KeyStates& keyState, std::unique_ptr<Command> command)
			:ControllerIdx{ controllerIdx }, GamepadButton{ gamepadButtons },KeyState{keyState},Command{std::move(command)}
		{
			
		}

		int ControllerIdx;
		GamepadButtons GamepadButton;
		KeyStates KeyState;
		std::unique_ptr<Command> Command;
	};


	struct KeyboardCommand final
	{
	
		KeyboardCommand( const SDL_Scancode& button, const KeyStates& keyState, std::unique_ptr<Command> command)
			: Button{ button }, KeyState{ keyState }, Command{ std::move(command) }
		{

		}

		SDL_Scancode Button;
		KeyStates KeyState;
		std::unique_ptr<Command> Command;
	};


	class InputManager final : public Singleton<InputManager>
	{
	public:
		InputManager();
		bool ProcessInput();

		void BindGamePadCommand(const int& controllerIdx, const GamepadButtons& gamepadButtons, const KeyStates& keyState, std::unique_ptr<Command> command);
		void BindKeyBoardCommand(const SDL_Scancode& button, const KeyStates& keyState, std::unique_ptr<Command> action);
	private:
		std::unique_ptr<KeyBoard> m_Keyboard;
		std::vector<std::unique_ptr<Gamepad>> m_Gamepads;
		std::vector<std::unique_ptr<GamepadCommand>> m_GamepadCommands;
		std::vector<std::unique_ptr<KeyboardCommand>> m_KeyboardCommands;

		int m_CurrentControler{};

		void HandleCommands();
	};

}
