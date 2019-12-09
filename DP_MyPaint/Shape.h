
#ifndef  _SHAPE2_H_
#define _SHAPE2_H_
#include <iostream>
#include <vector>
#include "Simple.h"
// shape���൱���Ƕ� line circle����״�� ���� 
// �Ӷ�ʵ�ֶ��ڱ仯�ĸ���
class Shape {
public:
	virtual void Draw() = 0; // ����Ӧ��������ʵ��ϸ��
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
    //ʵ���Լ���Draw�������Լ�
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

	//ʵ���Լ���Draw�������Լ�
	virtual void Draw() {
		std::cout << "RECT: " << std::endl;
		std::cout<< leftUp.x << " " << leftUp.y<<" "<<" "<< width<<" "<< height<<std::endl;
	}

};

class MainForm {
private:
	Point p1;
	Point p2;

	//���������״
	std::vector<Shape*> shapeVector; // Ϊ��ʵ�ֶ�̬�������û���ָ�룬���ܷŶ���

public:
	MainForm() {
	}
	virtual void OnMouseDown(const RandPoz& e);
	virtual void OnMouseUp(const RandPoz& e, int type);
	virtual void OnPaint();
};




















#endif // ! _SHAPE2_H_









