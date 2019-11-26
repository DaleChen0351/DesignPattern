#ifndef _SINGLETON_H_
#define _SINGLETON_H_


class Singleton {
private: // 将ctor 和copy ctor 写成private 否则 编译器会默认生成一个。
	Singleton(); // ctor 
	Singleton(const Singleton& other);// copy ctor 
public:
	static Singleton* getInstance(); // 类的静态成员函数只能使用类的静态成员变量 // https://blog.csdn.net/MoreWindows/article/details/6721430
	static Singleton* m_instance;
};













#endif // !_SINGLETON_H_

