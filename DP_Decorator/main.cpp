// DP_Decorator.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n"; 
	ISgnlQualityDetector* s1 = new TrackingDetector;// 等号左边的指针不重要，定义成基类还是子类的指针都可以
	ISgnlQualityDetector* s2 = new PMWDetector;
	

	ISgnlQualityDetector* s3 = new Expandclass(s1);// 也可以多层装饰
	s3->LongTermInvaildCondtion();
	s3->VaildSignalAtCurCycle();


}

// eg PrintFilter demo

// 适合简单的业务逻辑的叠加组合，如果是复杂的策略模式的排列组合，因为依然要new出很多对象指针，所以管理起来也很复杂
// 因此，并不是很适合用装饰模式