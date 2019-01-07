#ifndef DOT_H
#define DOT_H

#include<iostream>
#include <iomanip>
using namespace std;

class Dot {//field���ȗ��ɕ\������ړI
	//���͎��͍��㌴�_�ŉ����c���ŁC��������x,y���]
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
	int GetxtoW();//����悤(���㌴�_�ŉ����c��)
	int GetytoW();//����悤
	int GetxtoO();//�����p(x,y�����])
	int GetytoO();//�����p
	int toO();//�����ł���`���ɔ��]
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


