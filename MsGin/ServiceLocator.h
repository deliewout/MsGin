#pragma once
#include <memory>
#include "SoundSystem.h"
namespace dae
{
	class ServiceLocator final
	{
		
	public:
		static std::unique_ptr<SoundSystem> m_ssInstance;
		static SoundSystem& GetSoundSystem() { return *m_ssInstance; }
		static void RegisterSoundSystem(std::unique_ptr<SoundSystem>&& soundSystem) 
		{ 
			m_ssInstance = soundSystem == nullptr ? std::make_unique<NullSoundSystem>() : std::move(soundSystem);
		}
	};

}
