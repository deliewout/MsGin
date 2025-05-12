#pragma once
#include <SDL_mixer.h>

namespace dae
{
	using sound_id = unsigned short;
	class SoundSystem
	{
	public:
		virtual ~SoundSystem() = default;
		SoundSystem(const SoundSystem& other) = delete;
		SoundSystem(SoundSystem&& other) = delete;
		SoundSystem& operator=(const SoundSystem& other) = delete;
		SoundSystem& operator=(SoundSystem&& other) = delete;

		virtual void Play(const sound_id ìd, const float volume, const int loops)=0;
		virtual void SetVolume(float volume) = 0;
		virtual void Stop() = 0;

	protected:
		SoundSystem() = default;
	};

	class NullSoundSystem final :public SoundSystem
	{
	public:
		NullSoundSystem() = default;
		virtual void Play(const sound_id, const float, const int ) override {}
		virtual void SetVolume(float ) {}
		virtual void Stop() {}
	};
}


