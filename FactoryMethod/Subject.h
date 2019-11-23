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
	virtual ~ISubject(); // ����������麯��
	virtual void Notify(std::string str) ; // ����������
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

//��������
class SubjectFactory {
public:
	virtual ISubject* CreateSubject() = 0;
	virtual ~SubjectFactory() {};
};
// ����������
class FootballFactory : public SubjectFactory
{
public:
	virtual ISubject* CreateSubject()
	{
		return new FootballSub(); // ���ϣ���Ǵ��в�ͬ�����Ĺ��죬��ô����ô��ƹ������أ�
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

