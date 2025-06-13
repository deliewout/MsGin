#pragma once
#include <vector>
#include <string>

class LevelSelector
{
public:
	void AddLevel(const std::string& sceneName);
	void NextLevel();
	//void LoadSelectedLevel();
	//void SkipToNextLevel();

private:
	std::vector<std::string> m_Levels;
	int m_CurrentIndex{ 0 };
};

