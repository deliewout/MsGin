#pragma once

#include <Event.h>
namespace dae
{
	struct  PlayerDieEvent : public Event
	{
		PlayerDieEvent() = default;
	};

	struct DotCollected : public Event
	{
		DotCollected() = default;
	};

	struct MegaDotCollected : public Event
	{
		MegaDotCollected() = default;
	};

}
