#ifndef _SINGLETON_H_
#define _SINGLETON_H_

// 单例模式  目的是保证一个类仅有一个实例，并提供一个访问它的全局接口，该实例被所有程序模块所共享
class Singleton {
private: // 将ctor 和copy ctor 写成private 否则 编译器会默认生成一个。
	Singleton(); // ctor 
	Singleton(const Singleton& other);// copy ctor 
public:
	static Singleton* getInstance(); // 类的静态成员函数只能使用类的静态成员变量 // https://blog.csdn.net/MoreWindows/article/details/6721430
	static Singleton* m_instance;
};

//apollo的单例模式  https://blog.csdn.net/liyi1149549057/article/details/100661450


// PS:
// DISALLOW_COPY_AND_ASSIGN 
// 运行new多个对象, 但是不允许 赋值构造和 等号赋值

// 补充apollo的单例模式代码





#endif // !_SINGLETON_H_

