#ifndef _SUBJECT_H
#define _SUBJECT_H
//#include <string>
//#include <list>


//// 抽象的接口
//class Interface {
//public:
//	virtual void DoProgress(float value) = 0;
//	virtual ~Interface() {}
//};
//
//class Subject
//{
//private:
//	std::list<Interface*>  m_InterfaceList; // 定义多个抽象基类指针。实现抽象通知机制，支持多个抽象观察者
//
//public:
//	void Run();
//	void Attach(Interface* iprogress);// 增加观察者
//	void Detach(Interface* iprogress);
//	~Subject();
//
//protected: // 可以被FileSplitter子类继承
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

