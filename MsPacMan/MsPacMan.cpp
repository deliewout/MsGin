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
#include "MuteCommand.h"
#include "LevelCommands.h"
#include "LevelSelector.h"

void LoadStartScreen()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("StartScreen");
	//auto& input = dae::InputManager::GetInstance();

	//SDL_GetWindowSize()

	auto logo = std::make_shared<dae::GameObject>();
	auto texture = dae::ResourceManager::GetInstance().LoadTexture("Logo.jpg");
	auto render = logo->AddComponent<dae::RenderComponent>();
	logo->GetTransform()->SetLocalPos(80, 80);
	logo->GetTransform()->SetWorldScale(2.f, 2.f);
	render->Settexture(texture);
	
	scene.Add(logo);

	auto player1 = std::make_shared<dae::GameObject>();
	texture = dae::ResourceManager::GetInstance().LoadTexture("1Player.jpg");
	render = player1->AddComponent<dae::RenderComponent>();
	player1->GetTransform()->SetLocalPos(160, 240);
	player1->GetTransform()->SetWorldScale(2.f, 2.f);
	render->Settexture(texture);

	scene.Add(player1);

	auto player2 = std::make_shared<dae::GameObject>();
	texture = dae::ResourceManager::GetInstance().LoadTexture("2Player.jpg");
	render = player2->AddComponent<dae::RenderComponent>();
	player2->GetTransform()->SetLocalPos(160, 280);
	player2->GetTransform()->SetWorldScale(2.f, 2.f);
	render->Settexture(texture);

	scene.Add(player2);

	auto versus = std::make_shared<dae::GameObject>();
	texture = dae::ResourceManager::GetInstance().LoadTexture("Versus.jpg");
	render = versus->AddComponent<dae::RenderComponent>();
	versus->GetTransform()->SetLocalPos(170, 320);
	versus->GetTransform()->SetWorldScale(2.f, 2.f);
	render->Settexture(texture);

	scene.Add(versus);

}
void LoadFirstLevel()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Level1");
	auto& input = dae::InputManager::GetInstance();

	const float movementSpeed{ 2.f };

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
	level->GetTransform()->SetLocalPos({ 0,80 });
	level->GetTransform()->SetWorldScale(2.5f, 2.5f);
	newTexture->Settexture(texture);
	scene.Add(level);


	auto MsPacMan = std::make_shared<dae::GameObject>();
	texture = dae::ResourceManager::GetInstance().LoadTexture("Sprites/MsPacman.jpg");
	newTexture = MsPacMan->AddComponent<dae::RenderComponent>();
	newTexture->Settexture(texture);
	MsPacMan->GetTransform()->SetLocalPos(80, 140);
	MsPacMan->AddComponent<HealthComponent>(3);
	scene.Add(MsPacMan);

	input.BindGamePadCommand(0, dae::GamepadButtons::Dpad_Left, dae::KeyStates::pressed, std::make_unique<PlayerMoveCommand>(MsPacMan, glm::vec2{ -1,0 }, movementSpeed));
	input.BindGamePadCommand(0, dae::GamepadButtons::Dpad_Right, dae::KeyStates::pressed, std::make_unique<PlayerMoveCommand>(MsPacMan, glm::vec2{ 1,0 }, movementSpeed));
	input.BindGamePadCommand(0, dae::GamepadButtons::Dpad_Down, dae::KeyStates::pressed, std::make_unique<PlayerMoveCommand>(MsPacMan, glm::vec2{ 0,1 }, movementSpeed));
	input.BindGamePadCommand(0, dae::GamepadButtons::Dpad_Up, dae::KeyStates::pressed, std::make_unique<PlayerMoveCommand>(MsPacMan, glm::vec2{ 0,-1 }, movementSpeed));

	input.BindKeyBoardCommand(SDL_SCANCODE_F2, dae::KeyStates::down, std::make_unique<MuteCommand>());

	auto Pacman = std::make_shared<dae::GameObject>();
	texture = dae::ResourceManager::GetInstance().LoadTexture("Sprites/Pacman.jpg");
	newTexture = Pacman->AddComponent<dae::RenderComponent>();
	newTexture->Settexture(texture);
	Pacman->GetTransform()->SetLocalPos(100, 140);
	scene.Add(Pacman);

	input.BindKeyBoardCommand(SDL_SCANCODE_LEFT, dae::KeyStates::pressed, std::make_unique<PlayerMoveCommand>(Pacman, glm::vec2{ -1,0 }, movementSpeed));
	input.BindKeyBoardCommand(SDL_SCANCODE_RIGHT, dae::KeyStates::pressed, std::make_unique<PlayerMoveCommand>(Pacman, glm::vec2{ 1,0 }, movementSpeed));
	input.BindKeyBoardCommand(SDL_SCANCODE_DOWN, dae::KeyStates::pressed, std::make_unique<PlayerMoveCommand>(Pacman, glm::vec2{ 0,1 }, movementSpeed));
	input.BindKeyBoardCommand(SDL_SCANCODE_UP, dae::KeyStates::pressed, std::make_unique<PlayerMoveCommand>(Pacman, glm::vec2{ 0,-1 }, movementSpeed));
}

void load()
{
	
	auto& input = dae::InputManager::GetInstance();
#if _DEBUG
	dae::ServiceLocator::RegisterSoundSystem(std::make_unique<dae::LogSoundSystem>(std::make_unique<dae::SDLSoundSystem>()));
#else
	dae::ServiceLocator::RegisterSoundSystem(std::make_unique<dae::SDLSoundSystem>());
#endif
	LevelSelector levelSelector;
	levelSelector.AddLevel("StartScreen");
	levelSelector.AddLevel("Level1");

	LoadStartScreen();
	LoadFirstLevel();


	auto& soundSystem = dae::ServiceLocator::GetSoundSystem();
	soundSystem.SetVolume(10);
	soundSystem.LoadMusic("Sounds/ms_fright.wav");

	input.BindKeyBoardCommand(SDL_SCANCODE_F2, dae::KeyStates::pressed,std::make_unique<SkipLevelCommand>(levelSelector));
}

int main(int, char* []) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
	return 0;
}
