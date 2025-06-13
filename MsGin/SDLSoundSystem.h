#pragma once
#include "SoundSystem.h"
#include "mutex"
#include <map>
#include <thread>
#include <queue>

namespace dae
{
	class SDLSoundSystem final : public SoundSystem
	{
	public:
		SDLSoundSystem();
		virtual ~SDLSoundSystem();
		SDLSoundSystem(const SDLSoundSystem& other) = delete;
		SDLSoundSystem(SDLSoundSystem&& other) = delete;
		SDLSoundSystem& operator=(const SDLSoundSystem& other) = delete;
		SDLSoundSystem& operator=(SDLSoundSystem&& other) = delete;

		virtual void Play(const sound_id ìd, const float volume, const int loops) override;
		virtual void Mute() override;
		virtual void SetVolume(float volume) override;
		virtual void Stop()override;

		virtual void LoadMusic(const char* fileName) override;
		virtual void ProcessQueue() override;

	private:
		float m_Volume{ 5.f };
		bool m_Ismute{ false };

		int m_NextMusicId{0};

		std::map<sound_id, Mix_Music*> m_MusicMap;
		std::map<sound_id, Mix_Chunk*> m_SoundsMap;

		std::queue<std::pair<sound_id,int>> m_SoundQueue{};

		std::jthread m_Thread{};
		std::mutex m_Mutex{};
		std::condition_variable m_Cv{};
		bool m_IsPlaying{ false };

	};
}


