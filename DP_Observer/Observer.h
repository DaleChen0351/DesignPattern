#ifndef _OBSERVER_H_
#define _OBSERVER_H_


// ��������һ���۲��ߣ��̳��˽ӿ�
class ConsoleNotifier : public Interface {
public:
	virtual void DoProgress(float value) {
		std::cout << "This is a consoleNotifier !   the value is   " << value << std::endl;
	}
};

class MainForm : public Interface  // ���̳������ĸ��࣬������ӿ�
{

public:
// �̳�IProgress �ӿڱ���ʵ�ֵĺ���
	virtual void DoProgress(float value) {
		std::cout << "This is a progress bar!   the value is   " << value << std::endl;
	}
};





















#endif // !_OBSERVER

