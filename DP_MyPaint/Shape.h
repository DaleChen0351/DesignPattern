
#ifndef  _SHAPE2_H_
#define _SHAPE2_H_
#include <iostream>
#include <vector>
#include "Simple.h"
// shape类相当于是对 line circle等形状的 抽象 
// 从而实现对于变化的隔离
class Shape {
public:
	virtual void Draw() = 0; // 抽象不应该依赖于实现细节
	virtual ~Shape() { }
};

class Line : public Shape {
public:
	Point start;
	Point end;

	Line(const Point& start, const Point& end) {
		this->start = start;
		this->end = end;

	}
    //实现自己的Draw，负责画自己
	virtual void Draw() {
		std::cout << "LINE: " << std::endl;
		std::cout << start.x << " " << start.y << " " << " " << end.x << " " << end.y << std::endl;
	}

};

class Rect : public Shape {
public:
	Point leftUp;
	int width;
	int height;

	Rect(const Point& leftUp, int width, int height) {
		this->leftUp = leftUp;
		this->width = width;
		this->height = height;
	}

	//实现自己的Draw，负责画自己
	virtual void Draw() {
		std::cout << "RECT: " << std::endl;
		std::cout<< leftUp.x << " " << leftUp.y<<" "<<" "<< width<<" "<< height<<std::endl;
	}

};

class MainForm {
private:
	Point p1;
	Point p2;

	//针对所有形状
	std::vector<Shape*> shapeVector; // 为了实现多态，所以用基类指针，不能放对象

public:
	MainForm() {
	}
	virtual void OnMouseDown(const RandPoz& e);
	virtual void OnMouseUp(const RandPoz& e, int type);
	virtual void OnPaint();
};




















#endif // ! _SHAPE2_H_









