#pragma once

class Dot{//field���ȗ��ɕ\������ړI
public:
	Dot();
	~Dot();
	int Initialize();
	int up();
	int right();
	int left();
	int down();
private:
	int x;
	int y;
};

Dot::Dot()
{
}

Dot::~Dot()
{
}
