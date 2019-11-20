#include "pch.h"


//void Subject::Run()
//{
//	// 数据改变
//	for (int i = 0; i < 10; i++)
//	{
//		// 通知其他人
//		Notify(i);
//	}
//}
//void Subject::Attach(Interface* iprogress) {
//	m_InterfaceList.push_back(iprogress);
//}
//
//void Subject::Detach(Interface* iprogress) {
//	m_InterfaceList.remove(iprogress);
//}
//// virtual
//void Subject:: Notify(float value) {
//
//	std::list<Interface*>::iterator itor = m_InterfaceList.begin();
//
//	while (itor != m_InterfaceList.end())
//	{
//		(*itor)->DoProgress(value); //更新多个观察者
//		 itor++;
//	}
//		
//}
//
//Subject::~Subject()
//{
//	std::list<Interface*>::iterator itor = m_InterfaceList.begin();
//
//	while (itor != m_InterfaceList.end())
//	{
//		delete (*itor);
//		itor++;
//	}
//}

void ISubject::Attach(Interface* iprogress)
{
	m_InterfaceList.push_back(iprogress);
}

void ISubject::Detach(Interface* iprogress)
{
	m_InterfaceList.remove(iprogress);
}

void ISubject::Notify(float value)
{
	std::list<Interface*>::iterator itor = m_InterfaceList.begin();
	while (itor != m_InterfaceList.end())
	{
		(*itor)->DoProgress(value);
		itor++;
	}
}
void ISubject::Run()
{
	for (int i = 0; i < 10; i++)
	{
		Notify(i);
	}
}

ISubject::~ISubject()
{
	/*std::list<Interface*>::iterator itor = m_InterfaceList.begin();
	while (itor != m_InterfaceList.end())
	{
		delete *itor;
		itor++;
	}*/
	// list 中如果添加的是指针，应该如何清空

}

