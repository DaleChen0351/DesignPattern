// DP_MyPaint.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n"; 
	MainForm m;
	RandPoz pos;

	pos.setRandPoz(1, 2);
	m.OnMouseDown(pos);
	pos.setRandPoz(9, 9);
    m.OnMouseUp(pos, 1);

	pos.setRandPoz(10, 20);
	m.OnMouseDown(pos);
	pos.setRandPoz(80, 9);
	m.OnMouseUp(pos, 2);

	m.OnPaint();


}


