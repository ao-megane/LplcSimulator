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

int Dot::up() {
	y -= 1;
	return 0;
}
int Dot::down() {
	y += 1;
	return 0;
}
int Dot::right() {
	x += 1;
	return 0;
}
int Dot::left() {
	x -= 1;
	return 0;
}
int Dot::Getx() {
	return x;
}
int Dot::Gety() {
	return y;
}

bool Dot::isCollect(int _x, int _y) {
	if (x == _x && y == _y) {
		return true;
	}
	return false;
}
