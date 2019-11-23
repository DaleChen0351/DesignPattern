// AbstractFactory.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n"; 
	IDBFactory* sqlF = new SqlDBFactory;
	EmployeeDAO e;
	e.dbFactory = sqlF;
	e.run();
	delete sqlF;
}


