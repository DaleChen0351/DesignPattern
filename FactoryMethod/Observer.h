#ifndef _OBSERVER_H_
#define _OBSERVER_H_

class BaseObserver // 观察者的基类
{
protected:
	std::string name_;
public:
	BaseObserver() : name_("BaseObserver") {}
	virtual void DoProgress(std::string str) = 0;
	virtual ~BaseObserver() {};// 必须是虚的析构函数
};
// 这是另外一个观察者，继承了接口
class ConsoleNotifier : public BaseObserver {
public:
	ConsoleNotifier() { name_ = "ConsoleNotifier"; }
	virtual void DoProgress(std::string str) {
		std::cout <<name_.c_str()<<"  received : "<< str.c_str()<< std::endl;
	}
};

class MainForm : public BaseObserver  // 单继承真正的父类，及多个接口
{

public:
	MainForm() { name_ = "MainForm"; }
	virtual void DoProgress(std::string str) {
		std::cout << name_.c_str() << "  received : " << str.c_str() << std::endl;
	}
};





















#endif // !_OBSERVER

