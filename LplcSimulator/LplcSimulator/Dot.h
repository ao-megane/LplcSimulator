#ifndef DOT_H
#define DOT_H

#include<iostream>
#include <iomanip>
using namespace std;

class Dot {//fieldを簡略に表現する目的
	//入力時は左上原点で横ｘ縦ｙで，処理時はx,y反転
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
	int GetxtoW();//見るよう(左上原点で横ｘ縦ｙ)
	int GetytoW();//見るよう
	int GetxtoO();//処理用(x,yが反転)
	int GetytoO();//処理用
	int toO();//処理できる形式に反転
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


