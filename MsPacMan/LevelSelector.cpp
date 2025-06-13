#include "LevelSelector.h"
#include <SceneManager.h>

void LevelSelector::AddLevel(const std::string& sceneName)
{
	m_Levels.push_back(sceneName);
}

void LevelSelector::NextLevel()
{
	m_CurrentIndex = (m_CurrentIndex + 1) % m_Levels.size();
}

