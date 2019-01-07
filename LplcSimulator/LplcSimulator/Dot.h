#ifndef DOT_H
#define DOT_H

#include<iostream>
#include <iomanip>
using namespace std;

class Dot {//field���ȗ��ɕ\������ړI
	//x,y�͐��w�Ƌt(x,y���])
public:
	Dot();
	~Dot();
	int Initialize();
	int Set(int x, int y);
	int up();
	int right();
	int left();
	int down();
	Dot upDot();
	Dot rightDot();
	Dot leftDot();
	Dot downDot();
	Dot reverseDot();
	int Getx();	//������y
	int Gety();	//������x
	int testDraw();
	void operator = (Dot a) {
		x = a.x;
		y = a.y;
	}
	bool isCollect(int x, int y);
private:
	int x;
	int y;
};

#endif // !DOT_H


