#include "Subject.h"

void dae::Subject::AddObserver(Observer* pObserver)
{
	if (std::find(m_pObservers.begin(),m_pObservers.end(),pObserver)==m_pObservers.end())
	m_pObservers.emplace_back(pObserver);
}

void dae::Subject::RemoveObserver(Observer* pObserver)
{
	m_pObservers.erase(std::remove(m_pObservers.begin(), m_pObservers.end(), pObserver), m_pObservers.end());
}
