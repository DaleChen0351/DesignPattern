#ifndef _SUBJECT_H
#define _SUBJECT_H
//#include <string>
//#include <list>






class Interface // �۲��ߵĻ���
{
public:
	virtual void DoProgress(float value) = 0;
	virtual ~Interface() {};// �����������������
};
class Subject
{
private:
	std::list<Interface*> m_InterfaceList;// ����������
public:
	void Attach(Interface* iprogress);
	void Detach(Interface* iprogress);
	void Run();
	~Subject();
protected:
	virtual void Notify(float value);// �ɱ��̳�
};














#endif // !_SUBJECT_H

