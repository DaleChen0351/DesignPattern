#ifndef _OBSERVER_H_
#define _OBSERVER_H_

class BaseObserver // �۲��ߵĻ���
{
protected:
	std::string name_;
public:
	BaseObserver() : name_("BaseObserver") {}
	virtual void DoProgress(std::string str) = 0;
	virtual ~BaseObserver() {};// �����������������
};
// ��������һ���۲��ߣ��̳��˽ӿ�
class ConsoleNotifier : public BaseObserver {
public:
	ConsoleNotifier() { name_ = "ConsoleNotifier"; }
	virtual void DoProgress(std::string str) {
		std::cout <<name_.c_str()<<"  received : "<< str.c_str()<< std::endl;
	}
};

class MainForm : public BaseObserver  // ���̳������ĸ��࣬������ӿ�
{

public:
	MainForm() { name_ = "MainForm"; }
	virtual void DoProgress(std::string str) {
		std::cout << name_.c_str() << "  received : " << str.c_str() << std::endl;
	}
};





















#endif // !_OBSERVER

