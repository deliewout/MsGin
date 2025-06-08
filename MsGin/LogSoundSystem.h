#pragma once
#include "SoundSystem.h"
#include "memory"
#include <iostream>
namespace dae
{
	class LogSoundSystem final: public SoundSystem 
	{
	private:
		std::unique_ptr<SoundSystem> m_RealSs;
	public:
		LogSoundSystem(std::unique_ptr<SoundSystem>&& ss): m_RealSs(std::move(ss)){}
		virtual ~LogSoundSystem() = default;

		void Play(const sound_id id, const float volume, const int loops) override
		{
			m_RealSs->Play(id, volume,loops);
			std::cout << "playing " << id << " at volume " << volume << " looping "<< loops << " times" << std::endl;
		}
		virtual void SetVolume(float volume)
		{
			m_RealSs->SetVolume(volume);
		}
		virtual int LoadMusic(const char* fileName) override
		{
			m_RealSs->LoadMusic(fileName);
			return 0;
		}
		virtual void Stop()
		{
			m_RealSs->Stop();
		}
	
	};
}


