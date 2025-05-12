#pragma once
#include "SoundSystem.h"
#include "mutex"
#include <map>
namespace dae
{
	class SDLSoundSystem final : public SoundSystem
	{
	public:
		SDLSoundSystem()=default;
		virtual ~SDLSoundSystem();
		SDLSoundSystem(const SDLSoundSystem& other) = delete;
		SDLSoundSystem(SDLSoundSystem&& other) = delete;
		SDLSoundSystem& operator=(const SDLSoundSystem& other) = delete;
		SDLSoundSystem& operator=(SDLSoundSystem&& other) = delete;

		virtual void Play(const sound_id ìd, const float volume, const int loops) override;
		virtual void SetVolume(float volume) override;
		virtual void Stop()override;

	private:
		float m_Volume{ 1.f };
		std::mutex m_Mutex{};

		std::map<sound_id, Mix_Music*> m_MusicMap;

	};
}


