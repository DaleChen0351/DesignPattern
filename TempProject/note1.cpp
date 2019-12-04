#include "pch.h"

#include <memory>

// C++11 针对内存管理的改进： new and delete
void version_one()
{
	int* age = new int(25);
	delete age;
// verson one for C
	int* ageC = (int*)malloc(sizeof(int)); // malloc 的返回值是void* 的， 可以指向任何东西
	free(ageC); // 可以释放任何东西

	char* c = (char*)malloc(100);
	free(c);
// Q1 : free 函数传入的是一个void* 的指针， 系统如何知道要释放多大的内存空间呢？

}
// Q2 为啥C++没有沿用free 和 malloc函数呢？
// 


//单纯只看函数的声明是无法确定是否需要我们手动释放指针：设计的缺陷导致的
	// 1 不需要释放指针的情况
const char*  getName() // const 指针不能改变指向,且这个函数中第二次调用时，指针指向的值就变了？
{
	static char valueGroup[100];
	//
	return valueGroup;
}
	// 2 需要我们释放指针的情况： 因为是malloc分配的，需要free掉。和new出来的一样。
const char* getName2()// 
{
	char* value = (char*)malloc(100);// 动态分配的，需要释放
	return value;
}
	// 3 是否释放由函数的外部掌控
char* getName(char* v, size_t bufferSize)
{
	return v;
}

// delete and delete[]

// 最关键的是即使没有逻辑错误，但是由于异常抛出，仍有可能造成内存泄漏

void throwout()
{
	int* c = new int(8);
	// throw out
	
	delete c;// 不会再次调用delete了
}
// 利用构造和析构成对出现来解决这个问题
// 安全的 粗糙版本的：构造的时候动态分配内存 析构的时候释放掉
class SaveIntPointer
{
public:
	explicit SaveIntPointer(int v) : m_value(new int(v)), m_used(1){}
	~SaveIntPointer() { 
		// 单线程没有问题，多线程是错误的
		m_used--;
		if(m_used <=0)
			delete m_value;// 多线程情况下有可能被delete两遍
	}
	// 正确实现 copy ctor
	// operator = 
	int* get() { return m_value; }
private:
	int m_used;
	int* m_value;
};

//C++ 11中 多个指针的情况 shard_pointer 是专门解决这个问题的
// 效率 
// 利用构造和析构，除了作用域，就一定会自动调用析构函数，哪怕中间抛出了异常