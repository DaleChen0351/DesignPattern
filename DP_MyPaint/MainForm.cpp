#include "pch.h"


//void MainForm::OnMouseDown(const RandPoz& e) {
//	p1.x = e.X;
//	p1.y = e.Y;
//}
//
//void MainForm::OnMouseUp(const RandPoz& e, int type) {
//	p2.x = e.X;
//	p2.y = e.Y;
//
//	if ( 1 == type) {
//		shapeVector.push_back(new Line(p1, p2)); // 不可以放栈对象，而是放一个堆对象指针。另外， 记住释放
//	}
//	else if (2 == type) {
//		int width = abs(p2.x - p1.x);
//		int height = abs(p2.y - p1.y);
//		shapeVector.push_back(new Rect(p1, width, height));
//	}
//}
//// 打印输出
//void MainForm::OnPaint() {
//
//	//针对所有形状
//	for (int i = 0; i < shapeVector.size(); i++) {
//
//		shapeVector[i]->Draw(); //多态调用，各负其责
//	}
//
//}

void MainForm::OnMouseDown(const RandPoz& pos)
{
	this->p1.x = pos.X;
	this->p1.y = pos.Y;
}

void MainForm::OnMouseUp(const RandPoz& pos, int type)
{
	this->p2.x = pos.X;
	this->p2.y = pos.Y;

	if (1 == type)
	{
		shapeVector.push_back(new Line(p1, p2));
	}
	// new sth
}
void MainForm::OnPaint()
{
	for (int i = 0; i < shapeVector.size(); i++)
	{
		shapeVector[i]->Draw();// 多态调用，各负其责
	}
}

MainForm::~MainForm()
{
	for (int i = 0; i < shapeVector.size(); i++)
	{
		delete shapeVector[i];
	}
}
