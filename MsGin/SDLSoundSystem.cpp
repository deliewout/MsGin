#include "SDLSoundSystem.h"

dae::SDLSoundSystem::~SDLSoundSystem()
{
	m_IsPlaying = false;
	m_Cv.notify_one();
	Mix_Quit();
}

void dae::SDLSoundSystem::Play(const sound_id id, const float , const int loops)
{
	auto audioClip = m_SoundsMap[id];
	std::unique_lock<std::mutex> lock(m_Mutex);
	//m_Cv.wait(lock);
	Mix_VolumeMusic(static_cast<int>(128 * 10));
	Mix_PlayChannel(-1, audioClip, loops);
	
}

void dae::SDLSoundSystem::SetVolume(float )
{
	//Mix_Volume(-1, volume);
}

void dae::SDLSoundSystem::Stop()
{
	Mix_HaltMusic();
}

int dae::SDLSoundSystem::LoadMusic(const char* fileName)
{
	Mix_Chunk* music=  Mix_LoadWAV(fileName);
	sound_id id = static_cast<sound_id>(m_MusicMap.size());
	m_SoundsMap[id] = music;

	Play(id, 0, 1);
	return static_cast<int>(id);
}
