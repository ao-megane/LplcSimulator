#include"Dot.h"

int Dot::Initialize() {
	x = 0;
	y = 0;
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