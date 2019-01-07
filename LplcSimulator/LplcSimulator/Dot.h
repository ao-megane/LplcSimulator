#ifndef DOT_H
#define DOT_H

#include<iostream>
#include <iomanip>
using namespace std;

class Dot {//field‚ğŠÈ—ª‚É•\Œ»‚·‚é–Ú“I
	//x,y‚Í”Šw‚Æ‹t(x,y”½“])
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
	int Getx();	//‚¢‚Â‚à‚Ìy
	int Gety();	//‚¢‚Â‚à‚Ìx
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


