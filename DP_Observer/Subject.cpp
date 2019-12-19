#include "pch.h"


//void Subject::Run()
//{
//	// ���ݸı�
//	for (int i = 0; i < 10; i++)
//	{
//		// ֪ͨ������
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
//		(*itor)->DoProgress(value); //���¶���۲���
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
// ʹ��list���Ժܷ����ά��һ����ҪƵ���������ɾ���Ķ��С�
void Subject::Attach(Interface* iprogress)
{
	m_InterfaceList.push_back(iprogress);
}

void Subject::Detach(Interface* iprogress)
{
	m_InterfaceList.remove(iprogress);// ʱ�临�Ӷ�On��
}

void Subject::Notify(float value)
{
	std::list<Interface*>::iterator itor = m_InterfaceList.begin();
	while (itor != m_InterfaceList.end())
	{
		(*itor)->DoProgress(value);
		itor++;
	}
}
void Subject::Run()
{
	for (int i = 0; i < 10; i++)
	{
		Notify(i);
	}
}

Subject::~Subject()
{
	/*std::list<Interface*>::iterator itor = m_InterfaceList.begin();
	while (itor != m_InterfaceList.end())
	{
		delete *itor;
		itor++;
	}*/
	// list �������ӵ���ָ�룬Ӧ��������

}

