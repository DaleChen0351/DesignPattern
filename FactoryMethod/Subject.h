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




class ISubject
{
protected:
	std::list<Interface*> m_InterfaceList;
public:
	virtual void Attach(Interface* iprogress) ;
	virtual void Detach(Interface* iprogress) ;
	virtual void Run();
	~ISubject() {};
protected:
	virtual void Notify(float value);// 
};

class FootBallSub :public ISubject
{
public:
	virtual void Run()
	{
		
	}
};














#endif // !_SUBJECT_H

