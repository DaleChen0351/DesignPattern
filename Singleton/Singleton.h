#ifndef _SINGLETON_H_
#define _SINGLETON_H_


class Singleton {
private: // ��ctor ��copy ctor д��private ���� ��������Ĭ������һ����
	Singleton(); // ctor 
	Singleton(const Singleton& other);// copy ctor 
public:
	static Singleton* getInstance(); // ��ľ�̬��Ա����ֻ��ʹ����ľ�̬��Ա���� // https://blog.csdn.net/MoreWindows/article/details/6721430
	static Singleton* m_instance;
};













#endif // !_SINGLETON_H_

