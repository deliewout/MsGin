#pragma once
#include <vector>

#include "Component.h"

namespace dae
{
	class TrashTheCache final : public Component
	{
	public:
		TrashTheCache(GameObject* pOwner):Component(pOwner){}

		~TrashTheCache() override =default;
		TrashTheCache(const TrashTheCache& other) = delete;
		TrashTheCache(TrashTheCache&& other) = delete;
		TrashTheCache& operator=(const TrashTheCache& other) = delete;
		TrashTheCache& operator=(TrashTheCache&& other) = delete;

		virtual void OnGui() override;

	private:
		struct Transform
		{
			float matrix[16] = 
			{
				1,0,0,0,
				0,1,0,0,
				0,0,1,0,
				0,0,0,1
			};
		};
		class GameObject3D
		{
		public:
			Transform transform;
			int ID{};
		};
		class AltGameObject3D
		{
		public:
			Transform* transform;
			int ID{};
		};

		const int m_BufferAmount{ 100000000 };

		void RenderEx1();
		void RenderEx2();

		int m_IntSamplesAmount{ 10 };
		int m_GOSamplesAmount{ 10 };

		std::vector<float> m_IntSamples;
		std::vector<float> m_GameObjectSamples;
		std::vector<float> m_AltGameObjectSamples;

		void ExInts();
		void ExGameObject();
		void ExAltGameObject();

	};
}


