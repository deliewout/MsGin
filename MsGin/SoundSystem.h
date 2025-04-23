#pragma once
#include <SDL_mixer.h>

namespace dae
{
	using sound_id = unsigned short;
	class SoundSystem
	{
	public:
		virtual ~SoundSystem() = default;
		virtual void Play(const sound_id �d, const float volume)=0;
	};
}


