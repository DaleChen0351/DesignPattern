#include "pch.h"

void ISubject::Attach(BaseObserver* baseObs)
{
	m_InterfaceList.push_back(baseObs);
}

void ISubject::Detach(BaseObserver* baseObs)
{
	m_InterfaceList.remove(baseObs);
}

void ISubject::Notify(std::string str)
{
	std::list<BaseObserver*>::iterator itor = m_InterfaceList.begin();
	while (itor != m_InterfaceList.end())
	{
		(*itor)->DoProgress(str);
		itor++;
	}
}


ISubject::~ISubject()
{
	
}

