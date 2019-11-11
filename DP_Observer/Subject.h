#ifndef _SUBJECT_H
#define _SUBJECT_H
//#include <string>
//#include <list>


//// ����Ľӿ�
//class Interface {
//public:
//	virtual void DoProgress(float value) = 0;
//	virtual ~Interface() {}
//};
//
//class Subject
//{
//private:
//	std::list<Interface*>  m_InterfaceList; // �������������ָ�롣ʵ�ֳ���֪ͨ���ƣ�֧�ֶ������۲���
//
//public:
//	void Run();
//	void Attach(Interface* iprogress);// ���ӹ۲���
//	void Detach(Interface* iprogress);
//	~Subject();
//
//protected: // ���Ա�FileSplitter����̳�
//	virtual void Notify(float value);
//};



class Interface // �۲��ߵĻ���
{
public:
	virtual void DoProgress(float value) = 0;
	virtual ~Interface() {};// �����������������
};
class Subject
{
private:
	std::list<Interface*> m_InterfaceList;
public:
	void Attach(Interface* iprogress);
	void Detach(Interface* iprogress);
	void Run();
	~Subject();
protected:
	virtual void Notify(float value);// �ɱ��̳�
};














#endif // !_SUBJECT_H

