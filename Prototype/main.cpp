// Prototype.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n"; 
	ISplitter* is = new TxtSplitter;
	is->test_num = 10; // 以该参数为10的对象作为原型对象，传入client中，client中调用clone函数，复制出一样的对象作为模板，实现功能
	MainForm m(is);
	m.Button_Click();
}


