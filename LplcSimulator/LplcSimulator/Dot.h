#pragma once

class Dot{//fieldを簡略に表現する目的
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
