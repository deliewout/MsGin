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

		virtual void LoadMusic(const char* fileName) override
		{
			m_RealSs->LoadMusic(fileName);
			std::cout << "loaded sound from file " << fileName << std::endl;
		}

		virtual void ProcessQueue() override
		{
			m_RealSs->ProcessQueue();
			std::cout << "processing the queue\n";
		}

		virtual void Mute() override
		{
			m_RealSs->Mute();
			std::cout << "sound is muted\n";
		}
		virtual void SetVolume(float volume) override
		{
			m_RealSs->SetVolume(volume);
			std::cout << "Volume has been set to " << volume << std::endl;
		}

		virtual void Stop() override
		{
			m_RealSs->Stop();
			std::cout << "The sound has stopped playing\n";
		}
	
	};
}


