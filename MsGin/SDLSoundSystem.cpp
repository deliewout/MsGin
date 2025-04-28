#include "SDLSoundSystem.h"

void dae::SDLSoundSystem::Play(const sound_id, const float volume)
{
	std::unique_lock<std::mutex> lock(m_Mutex);
	volume;
}

void dae::SDLSoundSystem::SetVolume(float volume)
{
	m_Volume = volume;
}

void dae::SDLSoundSystem::Stop()
{
}
