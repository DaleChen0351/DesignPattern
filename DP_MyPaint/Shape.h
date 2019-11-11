
#ifndef  _SHAPE2_H_
#define _SHAPE2_H_
#include <iostream>
#include <vector>
#include "Simple.h"
// shape类相当于是对 line circle等形状的 抽象 
// 从而实现对于变化的隔离
//class Shape {
//public:
//	virtual void Draw() = 0; // 抽象不应该依赖于实现细节
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
//    //实现自己的Draw，负责画自己
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
//	//实现自己的Draw，负责画自己
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
//	//针对所有形状
//	std::vector<Shape*> shapeVector; // 为了实现多态，所以用基类指针，不能放对象
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
	std::vector<Shape*>shapeVector; // 不将类中的变量类型声明成特定的具体类 （Line,Rect)，而是声明为某个接口(Shape or Shape*)。 “针对接口编程”
public:                              // 然后在本类的方法中，只需要使用接口（shape）的通用方法就可以了
	void OnMouseDown(const RandPoz& pos);
	void OnMouseUp(const RandPoz& pos, const int type);
	void OnPaint();
	~MainForm();
};
















#endif // ! _SHAPE2_H_









