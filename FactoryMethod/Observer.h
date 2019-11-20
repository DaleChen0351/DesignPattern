#ifndef _OBSERVER_H_
#define _OBSERVER_H_

class Interface // 观察者的基类
{
public:
	virtual void DoProgress(float value) = 0;
	virtual ~Interface() {};// 必须是虚的析构函数
};
// 这是另外一个观察者，继承了接口
class ConsoleNotifier : public Interface {
public:
	virtual void DoProgress(float value) {
		std::cout << "This is a consoleNotifier !   the value is   " << value << std::endl;
	}
};

class MainForm : public Interface  // 单继承真正的父类，及多个接口
{

public:
// 继承IProgress 接口必须实现的函数
	virtual void DoProgress(float value) {
		std::cout << "This is a progress bar!   the value is   " << value << std::endl;
	}
};





















#endif // !_OBSERVER

