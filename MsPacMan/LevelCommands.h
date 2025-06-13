#pragma once
#include <Command.h>
#include "LevelSelector.h"

class SkipLevelCommand : public Command
{
public:
    SkipLevelCommand(LevelSelector& selector) : m_Selector(selector) {}
    void Execute() override {/* m_Selector.SkipToNextLevel();*/ }
private:
    LevelSelector& m_Selector;
};