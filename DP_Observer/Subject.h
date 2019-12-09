#ifndef _SUBJECT_H
#define _SUBJECT_H
//#include <string>
//#include <list>






class Interface // 观察者的基类
{
public:
	virtual void DoProgress(float value) = 0;
	virtual ~Interface() {};// 必须是虚的析构函数
};
class Subject
{
private:
	std::list<Interface*> m_InterfaceList;// 析构函数？
public:
	void Attach(Interface* iprogress);
	void Detach(Interface* iprogress);
	void Run();
	~Subject();
protected:
	virtual void Notify(float value);// 可被继承
};














#endif // !_SUBJECT_H

