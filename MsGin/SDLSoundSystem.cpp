#include "SDLSoundSystem.h"

dae::SDLSoundSystem::~SDLSoundSystem()
{
	Mix_Quit();
}

void dae::SDLSoundSystem::Play(const sound_id id, const float volume, const int loops)
{
	std::unique_lock<std::mutex> lock(m_Mutex);
	Mix_PlayMusic(m_MusicMap[id], loops);
	volume;
}

void dae::SDLSoundSystem::SetVolume(float volume)
{
	m_Volume = volume;
}

void dae::SDLSoundSystem::Stop()
{
	Mix_HaltMusic();
}
