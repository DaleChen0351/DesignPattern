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



class Interface // 观察者的基类
{
public:
	virtual void DoProgress(float value) = 0;
	virtual ~Interface() {};// 必须是虚的析构函数
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
	virtual void Notify(float value);// 可被继承
};














#endif // !_SUBJECT_H

