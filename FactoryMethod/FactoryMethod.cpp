// FactoryMethod.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>


void testforfactory(SubjectFactory* factory)
{
	// 利用工厂模式生成一个订阅主题
	ISubject* sub;
	sub = factory->CreateSubject(); // new 出的对象 
	// 生成两个观察者
	MainForm* m = new MainForm ;
	ConsoleNotifier* cn = new ConsoleNotifier;// 另外一个观察者

	sub->Attach(m); //订阅通知  毕竟MainForm 继承了IProgress接口之后，也算是一个IProgress的子类了
	sub->Attach(cn); //订阅通知
	sub->Run();
	// 取消订阅
	sub->Detach(m);
	// sub->Detach(cn);

    delete sub;
	delete m;
	delete cn;
}





int main()
{
	std::cout << "Hello World!\n";
	FootballFactory f;
	GlobalFactory g;
	testforfactory(&f);
	testforfactory(&g);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
