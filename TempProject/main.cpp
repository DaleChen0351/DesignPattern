// TempProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>


class Base
{
protected:
	int j;

public:
	int i;
	void myfucn()
	{
	}

};

class Derived:public Base
{
public:
	void myfunction()
	{
		Derived son;
		son.j = 1; // ? why is there not needed the currrent object yet?
		std::cout << son.j << std::endl;
	}
};

class Bug
{
private:
	int m_legs;
	int m_color;
	
protected:
	int m_corns;
	void print_bug()
	{
		std::cout << m_legs << std::endl;
		std::cout << m_color << std::endl;
	}
public:
	Bug(int legs, int color) :m_legs(legs), m_color(color) {}; // 
	int public_num;
	

	void setLegs(int legs_n)
	{
		m_legs = legs_n;
	}
};

class Flybug :public Bug
{
private:
	int m_wings;
public:
	Flybug(int legs, int color, int wings) :Bug(legs, color), m_wings(wings) {};
	void print_bug()
	{
		Flybug b(20, 30,40);
		b.Bug::print_bug(); // protected 在子类中，及相当于是子类的private 成员，而类对象之间是互为友元的，因此
		b.m_wings = 3;  // private 成员函数及变量是可以修改和调用的。
		Bug::print_bug();
		std::cout << m_wings << std::endl;
	}
};

int main()
{
	
	std::cout << "Hello World!\n"; 
	Flybug f(2, 3, 4);
	f.print_bug();
	//f.Bug::print_bug(); // 调用基类的print_bug函数
}

// 1 若父类和子类的同名函数都是public的，则均可在外部调用
// 2 若父类的成员变量或者函数是protect的，则只能当成是子类自己的private成员使用，而不能在子类外部使用
// 3 若子类的成员函数中包含另外一个子类的对象，则子类中继承自父类的protected成员按照子类自身private成员处理，然后依然符合互为友元类的定义