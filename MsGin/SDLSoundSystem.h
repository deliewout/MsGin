#pragma once
#include "SoundSystem.h"
#include "mutex"
namespace dae
{
	class SDLSoundSystem final : public SoundSystem
	{
	public:
		SDLSoundSystem()=default;
		virtual ~SDLSoundSystem() = default;
		SDLSoundSystem(const SDLSoundSystem& other) = delete;
		SDLSoundSystem(SDLSoundSystem&& other) = delete;
		SDLSoundSystem& operator=(const SDLSoundSystem& other) = delete;
		SDLSoundSystem& operator=(SDLSoundSystem&& other) = delete;

		virtual void Play(const sound_id ìd, const float volume) override;
		virtual void ChangeVolume(float volume);
		virtual void Stop();

	private:
		float m_Volume{ 1.f };
		std::mutex m_Mutex{};

	};
}


