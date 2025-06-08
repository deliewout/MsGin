#if _DEBUG
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "Scene.h"
#include "ResourceManager.h"
#include "TextObject.h"
#include "GameObject.h"
#include "HealthComponent.h"
#include "InputManager.h"
#include "FPSComponent.h"
#include "RenderComponent.h"
#include "ServiceLocator.h"
#include "PlayerMoveCommand.h"
#include "SDLSoundSystem.h"
#include "LogSoundSystem.h"

void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");
	auto& input = dae::InputManager::GetInstance();
#if _DEBUG
	dae::ServiceLocator::RegisterSoundSystem(std::make_unique<dae::LogSoundSystem>(std::make_unique<dae::SDLSoundSystem>()));
#else
	dae::ServiceLocator::RegisterSoundSystem(std::make_unique<dae::SDLSoundSystem>());
#endif

	const float movementSpeed{ 2.f };

	//auto backGround = std::make_shared<dae::GameObject>();
	//auto texture = dae::ResourceManager::GetInstance().LoadTexture("background.tga");
	//auto newTexture = backGround->AddComponent<dae::RenderComponent>();
	//newTexture->Settexture(texture);
	//scene.Add(backGround);

	//auto logo = std::make_shared<dae::GameObject>();
	//texture = dae::ResourceManager::GetInstance().LoadTexture("logo.tga");
	//newTexture = logo->AddComponent<dae::RenderComponent>();
	//newTexture->Settexture(texture);
	//logo->GetTransform()->SetLocalPos(216, 180);
	//scene.Add(logo);

	//auto text = std::make_shared<dae::GameObject>();
	//auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	//auto to = text->AddComponent<dae::TextObject>();
	//to->SetFont(font);
	//to->SetText("Programming 4 assignment");
	//text->GetTransform()->SetLocalPos(80, 20);
	//scene.Add(text);

	auto fps = std::make_shared<dae::GameObject>();
	fps->GetTransform()->SetLocalPos(20, 60);
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 20);
	auto tc = fps->AddComponent<dae::TextObject>();
	tc->SetFont(font);
	tc->SetText("null");
	fps->AddComponent<dae::FPSComponent>();
	scene.Add(fps);

	auto level = std::make_shared<dae::GameObject>();
	auto texture = dae::ResourceManager::GetInstance().LoadTexture("Level/FirstLevel.jpg");
	auto newTexture = level->AddComponent<dae::RenderComponent>();
	level->GetTransform()->MoveLocalPosition({320,240});
	newTexture->Settexture(texture);
	scene.Add(level);


	auto MsPacMan = std::make_shared<dae::GameObject>();
	texture = dae::ResourceManager::GetInstance().LoadTexture("Sprites/MsPacman.jpg");
	newTexture = MsPacMan->AddComponent<dae::RenderComponent>();
	newTexture->Settexture(texture);
	MsPacMan->GetTransform()->SetLocalPos(80, 140);
	MsPacMan->AddComponent<HealthComponent>( 3);
	scene.Add(MsPacMan);

	input.BindGamePadCommand(0, dae::GamepadButtons::Dpad_Left, dae::KeyStates::pressed, std::make_unique<PlayerMoveCommand>(MsPacMan, glm::vec2{ -1,0 }, movementSpeed));
	input.BindGamePadCommand(0, dae::GamepadButtons::Dpad_Right, dae::KeyStates::pressed, std::make_unique<PlayerMoveCommand>(MsPacMan, glm::vec2{ 1,0 }, movementSpeed));
	input.BindGamePadCommand(0, dae::GamepadButtons::Dpad_Down, dae::KeyStates::pressed, std::make_unique<PlayerMoveCommand>(MsPacMan, glm::vec2{ 0,1 }, movementSpeed));
	input.BindGamePadCommand(0, dae::GamepadButtons::Dpad_Up, dae::KeyStates::pressed, std::make_unique<PlayerMoveCommand>(MsPacMan, glm::vec2{ 0,-1 }, movementSpeed));

	auto Pacman = std::make_shared<dae::GameObject>();
	texture = dae::ResourceManager::GetInstance().LoadTexture("Sprites/Pacman.jpg");
	newTexture = Pacman->AddComponent<dae::RenderComponent>();
	newTexture->Settexture(texture);
	Pacman->GetTransform()->SetLocalPos(100, 140);
	scene.Add(Pacman);

	input.BindKeyBoardCommand(SDL_SCANCODE_LEFT, dae::KeyStates::pressed, std::make_unique<PlayerMoveCommand>(Pacman, glm::vec2{ -1,0 },  movementSpeed));
	input.BindKeyBoardCommand(SDL_SCANCODE_RIGHT, dae::KeyStates::pressed, std::make_unique<PlayerMoveCommand>(Pacman, glm::vec2{ 1,0 },  movementSpeed));
	input.BindKeyBoardCommand(SDL_SCANCODE_DOWN, dae::KeyStates::pressed, std::make_unique<PlayerMoveCommand>(Pacman, glm::vec2{ 0,1 },  movementSpeed));
	input.BindKeyBoardCommand(SDL_SCANCODE_UP, dae::KeyStates::pressed, std::make_unique<PlayerMoveCommand>(Pacman, glm::vec2{ 0,-1 },  movementSpeed));
	//auto trashTheCacheObject = std::make_shared<dae::GameObject>();
	//trashTheCacheObject->AddComponent<dae::TrashTheCache>();
	//scene.Add(trashTheCacheObject);

	auto& soundSystem = dae::ServiceLocator::GetSoundSystem();
	soundSystem.LoadMusic("Sounds/ms_start.wav");

}

int main(int, char* []) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
	return 0;
}
