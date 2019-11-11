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
//		shapeVector.push_back(new Line(p1, p2)); // �����Է�ջ���󣬶��Ƿ�һ���Ѷ���ָ�롣���⣬ ��ס�ͷ�
//	}
//	else if (2 == type) {
//		int width = abs(p2.x - p1.x);
//		int height = abs(p2.y - p1.y);
//		shapeVector.push_back(new Rect(p1, width, height));
//	}
//}
//// ��ӡ���
//void MainForm::OnPaint() {
//
//	//���������״
//	for (int i = 0; i < shapeVector.size(); i++) {
//
//		shapeVector[i]->Draw(); //��̬���ã���������
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
		shapeVector[i]->Draw();// ��̬���ã���������
	}
}

MainForm::~MainForm()
{
	for (int i = 0; i < shapeVector.size(); i++)
	{
		delete shapeVector[i];
	}
}
