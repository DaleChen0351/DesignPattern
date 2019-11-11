
#ifndef  _SHAPE2_H_
#define _SHAPE2_H_
#include <iostream>
#include <vector>
#include "Simple.h"
// shape���൱���Ƕ� line circle����״�� ���� 
// �Ӷ�ʵ�ֶ��ڱ仯�ĸ���
//class Shape {
//public:
//	virtual void Draw() = 0; // ����Ӧ��������ʵ��ϸ��
//	virtual ~Shape() { }
//};
//
//class Line : public Shape {
//public:
//	Point start;
//	Point end;
//
//	Line(const Point& start, const Point& end) {
//		this->start = start;
//		this->end = end;
//
//	}
//    //ʵ���Լ���Draw�������Լ�
//	virtual void Draw() {
//		std::cout << "LINE: " << std::endl;
//		std::cout << start.x << " " << start.y << " " << " " << end.x << " " << end.y << std::endl;
//	}
//
//};
//
//class Rect : public Shape {
//public:
//	Point leftUp;
//	int width;
//	int height;
//
//	Rect(const Point& leftUp, int width, int height) {
//		this->leftUp = leftUp;
//		this->width = width;
//		this->height = height;
//	}
//
//	//ʵ���Լ���Draw�������Լ�
//	virtual void Draw() {
//		std::cout << "RECT: " << std::endl;
//		std::cout<< leftUp.x << " " << leftUp.y<<" "<<" "<< width<<" "<< height<<std::endl;
//	}
//
//};
//
//class MainForm {
//private:
//	Point p1;
//	Point p2;
//
//	//���������״
//	std::vector<Shape*> shapeVector; // Ϊ��ʵ�ֶ�̬�������û���ָ�룬���ܷŶ���
//
//public:
//	MainForm() {
//	}
//	virtual void OnMouseDown(const RandPoz& e);
//	virtual void OnMouseUp(const RandPoz& e, int type);
//	virtual void OnPaint();
//};
//


// test
class Shape
{
private:

public:
	virtual void Draw() = 0;
	// new sth
	~Shape() {};
};

class Line : public Shape
{
private:
	Point m_start;
	Point m_end;
public:
	Line(Point& start, Point& end) :m_start(start), m_end(end) {};
	virtual void Draw()
	{
		std::cout << "LINE: " << std::endl;
		std::cout << m_start.x << " " << m_start.y << " " << " " << m_end.x << " " << m_end.y << std::endl;
	}
};
// new a new class

class MainForm
{
private:
	Point p1;
	Point p2;
	std::vector<Shape*>shapeVector; // �������еı��������������ض��ľ����� ��Line,Rect)����������Ϊĳ���ӿ�(Shape or Shape*)�� ����Խӿڱ�̡�
public:                              // Ȼ���ڱ���ķ����У�ֻ��Ҫʹ�ýӿڣ�shape����ͨ�÷����Ϳ�����
	void OnMouseDown(const RandPoz& pos);
	void OnMouseUp(const RandPoz& pos, const int type);
	void OnPaint();
	~MainForm();
};
















#endif // ! _SHAPE2_H_









