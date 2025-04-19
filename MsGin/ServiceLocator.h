#pragma once
#include <memory>
#include "SoundSystem.h"
namespace dae
{
	class ServiceLocator final
	{
		static std::unique_ptr<SoundSystem> m_ssInstance;
	public:
		static SoundSystem& GetSoundSystem() { return *m_ssInstance; }
		static void RegisterSoundSystem(std::unique_ptr<SoundSystem>&& soundSystem) { m_ssInstance = std::move(soundSystem); }
	};
}
