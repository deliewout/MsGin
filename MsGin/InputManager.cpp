#include <SDL.h>
#include "InputManager.h"

#include <iostream>

#include "imgui.h"
#include "backends/imgui_impl_sdl2.h"

dae::InputManager::InputManager()
{
	m_Keyboard = std::make_unique<KeyBoardImpl>();
	for (int i{0};i<4;++i)
	{
		m_Gamepads.push_back(std::make_unique<Gamepad>(i));
	}
}

bool dae::InputManager::ProcessInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
		if (e.type == SDL_KEYDOWN) {
			
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			
		}

		ImGui_ImplSDL2_ProcessEvent(&e);
		// etc...

	}
	m_Keyboard->Update();
	for (auto& currGamepad:m_Gamepads)
	{
		if (currGamepad==nullptr)
			continue;
		currGamepad->ProcessGamepadInput();
	}
	HandleCommands();
	return true;
}

void dae::InputManager::BindGamePadCommand(const int& controllerIdx, const GamepadButtons& gamepadButtons, const KeyStates& keyState, std::unique_ptr<Command> command)
{
	m_GamepadCommands.push_back(std::make_unique<GamepadCommand>(controllerIdx, gamepadButtons, keyState, std::move(command)));
}

void dae::InputManager::BindKeyBoardCommand(const SDL_Scancode& button, const KeyStates& keyState, std::unique_ptr<Command> command)
{
	m_KeyboardCommands.push_back(std::make_unique<KeyboardCommand>(button, keyState, std::move(command)));
}

void dae::InputManager::RemoveGamePadCommand(const int& controllerIdx, const GamepadButtons& gamepadButtons, const KeyStates& keyState)
{
	auto it = std::remove_if(m_GamepadCommands.begin(), m_GamepadCommands.end(), [&](const std::unique_ptr<GamepadCommand>& cmd)
		{
			return cmd->ControllerIdx == controllerIdx &&
				cmd->GamepadButton == gamepadButtons &&
				cmd->KeyState == keyState;
		});
	m_GamepadCommands.erase(it, m_GamepadCommands.end());
}

void dae::InputManager::RemoveKeyBoardCommand(const SDL_Scancode& button, const KeyStates& keyState)
{
	auto it = std::remove_if(m_KeyboardCommands.begin(), m_KeyboardCommands.end(), [&](const std::unique_ptr<KeyboardCommand>& cmd)
		{
			return cmd->Button == button &&
				cmd->KeyState == keyState;
		});
	m_KeyboardCommands.erase(it, m_KeyboardCommands.end());
}

void dae::InputManager::HandleCommands()
{
	for (auto& command:m_GamepadCommands)
	{
		switch (command->KeyState)
		{
		case KeyStates::down:
			if (m_Gamepads[command->ControllerIdx]->IsButtonDown(static_cast<unsigned int>(command->GamepadButton)))
				command->Command->Execute();
			//std::cout << "hello\n";
			break;
		case KeyStates::up:
			if (m_Gamepads[command->ControllerIdx]->IsButtonUp(static_cast<unsigned int>(command->GamepadButton)))
				command->Command->Execute();
			break;
		case KeyStates::pressed:
			if (m_Gamepads[command->ControllerIdx]->IsButtonPressed(static_cast<unsigned int>(command->GamepadButton)))
				command->Command->Execute();
			
			break;
		}
	}

	for (auto& command :m_KeyboardCommands)
	{
		switch (command->KeyState)
		{
		case KeyStates::down:
			if (m_Keyboard->IsButtonDown(command->Button))
				command->Command->Execute();
			break;
		case KeyStates::up:
			if (m_Keyboard->IsButtonReleased(command->Button))
				command->Command->Execute();
			break;
		case KeyStates::pressed:
			if (m_Keyboard->IsButtonPressed(command->Button))
				command->Command->Execute();
			break;
		}
	}
}

