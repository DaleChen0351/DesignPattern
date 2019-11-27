#ifndef _SINGLETON_H_
#define _SINGLETON_H_

// ����ģʽ  Ŀ���Ǳ�֤һ�������һ��ʵ�������ṩһ����������ȫ�ֽӿڣ���ʵ�������г���ģ��������
class Singleton {
private: // ��ctor ��copy ctor д��private ���� ��������Ĭ������һ����
	Singleton(); // ctor 
	Singleton(const Singleton& other);// copy ctor 
public:
	static Singleton* getInstance(); // ��ľ�̬��Ա����ֻ��ʹ����ľ�̬��Ա���� // https://blog.csdn.net/MoreWindows/article/details/6721430
	static Singleton* m_instance;
};

//apollo�ĵ���ģʽ  https://blog.csdn.net/liyi1149549057/article/details/100661450


// PS:
// DISALLOW_COPY_AND_ASSIGN 
// ����new�������, ���ǲ����� ��ֵ����� �ȺŸ�ֵ

// ����apollo�ĵ���ģʽ����





#endif // !_SINGLETON_H_

