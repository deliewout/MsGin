#pragma once
#include "GameObject.h"

class Command
{
public:
	virtual ~Command()=default;
	virtual void Execute() = 0;
};


