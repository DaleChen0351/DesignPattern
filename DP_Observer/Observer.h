#ifndef _OBSERVER_H_
#define _OBSERVER_H_


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

