#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "FPSComponent.h"
#include "GameObject.h"
#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "TextObject.h"
#include "Scene.h"
#include "GameObject.h"
#include "RenderComponent.h"
#include "TrashTheCache.h"

void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	auto backGround = std::make_shared<dae::GameObject>();
	auto texture = dae::ResourceManager::GetInstance().LoadTexture("background.tga");
	auto newTexture = backGround->AddComponent<dae::RenderComponent>();
	newTexture->Settexture(texture);
	scene.Add(backGround);

	auto logo = std::make_shared<dae::GameObject>();
	texture = dae::ResourceManager::GetInstance().LoadTexture("logo.tga");
	newTexture = logo->AddComponent<dae::RenderComponent>();
	newTexture->Settexture(texture);
	logo->GetTransform()->SetLocalPos(216,180);
	scene.Add(logo);

	auto text = std::make_shared<dae::GameObject>();
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto to = text->AddComponent<dae::TextObject>();
	to->SetFont(font);
	to->SetText("Programming 4 assignment");
	text->GetTransform()->SetLocalPos(80,20);
	scene.Add(text);

	auto fps = std::make_shared<dae::GameObject>();
	fps->GetTransform()->SetLocalPos(20, 60);
	font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 20);
	auto tc = fps->AddComponent<dae::TextObject>();
	tc->SetFont(font);
	tc->SetText("null");
	fps->AddComponent<dae::FPSComponent>();
	scene.Add(fps);

	auto trashTheCacheObject = std::make_shared<dae::GameObject>();
	trashTheCacheObject->AddComponent<dae::TrashTheCache>();
	scene.Add(trashTheCacheObject);


}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}