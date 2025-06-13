#include "SDLSoundSystem.h"
#include <SDL_mixer.h>
#include <SDL.h>
#include <iostream>

dae::SDLSoundSystem::SDLSoundSystem()
{
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	{
		std::cout << "SDL can't be initiliazed:" << SDL_GetError() << std::endl;
	}
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096) < 0)
	{
		std::cout << "Audio can't be opened" << Mix_GetError() << std::endl;
	}
	m_Thread = std::jthread([this] {ProcessQueue(); });
}

dae::SDLSoundSystem::~SDLSoundSystem()
{
	m_IsPlaying = false;
	m_Cv.notify_one();
	m_Thread.join();

	for (auto& chunck : m_SoundsMap)
	{
		Mix_FreeChunk(chunck.second);
	}
	for (auto& music : m_MusicMap)
	{
		Mix_FreeMusic(music.second);
	}
	Mix_Quit();
}

void dae::SDLSoundSystem::Play(const sound_id id, const float , const int loops)
{
	{
		std::lock_guard<std::mutex> lock(m_Mutex);
		m_SoundQueue.push({ id,loops });
	}
	m_Cv.notify_one();
}

void dae::SDLSoundSystem::Mute()
{
	m_Ismute = !m_Ismute;

	if (m_Ismute)
	{
		Mix_VolumeMusic(0);
	}
	else
	{
		Mix_VolumeMusic(static_cast<int>(m_Volume));
	}
}

void dae::SDLSoundSystem::SetVolume(float volume)
{
	m_Volume = volume;
	if (!m_Ismute)
	{
		Mix_VolumeMusic(static_cast<int>(m_Volume));
	}
	
}

void dae::SDLSoundSystem::Stop()
{
	Mix_HaltMusic();
}

void dae::SDLSoundSystem::LoadMusic(const char* fileName)
{
	
	Mix_Music* music = Mix_LoadMUS(fileName);
	if (!music)
	{
		std::cout << "Failed to load music: " << Mix_GetError() << std::endl;
		return;
	}
	m_NextMusicId++;
	sound_id id = static_cast<sound_id>(m_NextMusicId);
	m_MusicMap[id] = music;
}

void dae::SDLSoundSystem::ProcessQueue()
{
	while (m_IsPlaying)
	{

		std::unique_lock<std::mutex> lock(m_Mutex);
		m_Cv.wait(lock, [this] {return !m_SoundQueue.empty(); });
		while (!m_SoundQueue.empty())
		{
			auto [id, loops] = m_SoundQueue.front();
			m_SoundQueue.pop();
			lock.unlock();

			auto musicIt = m_MusicMap.find(id);
			if (musicIt != m_MusicMap.end())
			{
				Mix_PlayMusic( musicIt->second, loops);
			}
			else
			{
				auto soundIt = m_SoundsMap.find(id);
				if (soundIt != m_SoundsMap.end())
				{
					Mix_PlayChannel(-1, soundIt->second, loops);
				}
			}
			lock.lock();
		}

	}
}
