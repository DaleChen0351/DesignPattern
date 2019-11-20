// DP_Bridge.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n"; 

	Payment*  p = new NetBankPayment(new CityPaymentSystem()); // for end customer and for bank
	p->MakePayment();

	delete p;

	//Payment* p2 = new CardPayment(new IDBAPaymentSystem());
	//p2->MakePayment();



 //bridge sensor fusion
	//Tracking* tr;
	//tr = new NewTracking();
	//tr->m_imp = new KF_HM_Exp();
	//tr->m_imp = new RadarMeasement(tr->m_imp);// 装饰类
	//

	//tr->Association();
	//tr->AssignedTrack();
	//tr->CreateNewTrack();

	//std::cout<<""<<std::endl;
	//tr->m_imp = new UKF_Matrix_Exp();
	//tr->Association();
	//tr->AssignedTrack();

	




}


