#ifndef _SUBJECT_H
#define _SUBJECT_H
//#include <string>
//#include <list>


class ISubject
{
protected:
	std::list<BaseObserver*> m_InterfaceList;
public:
	virtual void Attach(BaseObserver* baseObs) ;
	virtual void Detach(BaseObserver* baseObs) ;
	virtual void Run() = 0;
	virtual ~ISubject(); // 基类必须是虚函数
	virtual void Notify(std::string str) ; // 遍历订阅者
};

class FootballSub : public ISubject
{
public:
	virtual void Run()
	{
		Notify("Football match news");
	}
};

class GlobalNewsSub : public ISubject
{
public:
	virtual void Run()
	{
		Notify("Global economic news");
	}
};

//工厂基类
class SubjectFactory {
public:
	virtual ISubject* CreateSubject() = 0;
	virtual ~SubjectFactory() {};
};
// 工厂派生类
class FootballFactory : public SubjectFactory
{
public:
	virtual ISubject* CreateSubject()
	{
		return new FootballSub(); // 如果希望是带有不同参数的构造，那么该怎么设计工厂类呢？
	}
};
class GlobalFactory : public SubjectFactory
{
public:
	virtual ISubject* CreateSubject()
	{
		return new GlobalNewsSub();
	}
};
















#endif // !_SUBJECT_H

