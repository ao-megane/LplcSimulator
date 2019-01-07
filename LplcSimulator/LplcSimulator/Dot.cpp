#include"Dot.h"

Dot::Dot(){
	x = -1;
	y = -1;
}

Dot::~Dot(){
	x = -1;
	y = -1;
}

int Dot::Initialize() {
	x = -1;
	y = -1;
	return 0;
}
int Dot::Set(int _x, int _y) {
	x = _x;
	y = _y;
	return 0;
}

int Dot::up() {
	//x -= 1;
	y -= 1;
	return 0;
}
int Dot::down() {
	//x += 1;
	y += 1;
	return 0;
}
int Dot::right() {
	//y += 1;
	x += 1;
	return 0;
}
int Dot::left() {
	//y -= 1;
	x -= 1;
	return 0;
}
Dot Dot::upDot() {
	Dot result;
	result.Set(x, y);
	//result.Set(y, x);
	result.up();
	return result;
}
Dot Dot::downDot() {
	Dot result;
	result.Set(x, y);//ŽÊ‚·
	//result.Set(y, x);
	result.down();
	return result;
}
Dot Dot::rightDot() {
	Dot result;
	result.Set(x, y);
	//result.Set(y, x);
	result.right();
	return result;
}
Dot Dot::leftDot() {
	Dot result;
	result.Set(x, y);
	//result.Set(y, x);
	result.left();
	return result;
}
Dot Dot::reverseDot() {
	Dot result;
	result.Set(y, x);
	return result;
}
int Dot::GetxtoO() {
	return y;
}
int Dot::GetytoO() {
	return x;
}
int Dot::GetxtoW() {
	return y;
}
int Dot::GetytoW() {
	return x;
}

int Dot::toO() {
	double _x = x;
	x = y;
	y = _x;
	return 0;
}

bool Dot::isCollect(int _x, int _y) {
	if (x == _x && y == _y) {
		return true;
	}
	return false;
}
