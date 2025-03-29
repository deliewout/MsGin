#pragma once
#include <vector>
#include "Observer.h"
namespace dae
{
	enum class Events;

	class Subject
	{
	public:
		void AddObserver(Observer* pObserver);
		void RemoveObserver(Observer* pObserver);
	protected:
		void NotifyObservers(Events event)
		{
			for (auto observer : m_pObservers)
				observer->Notify(event, this);
		}
	private:
		std::vector<Observer*> m_pObservers;
	};
}


