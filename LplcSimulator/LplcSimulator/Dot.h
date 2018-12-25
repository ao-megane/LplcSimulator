#pragma once

class Dot{//field‚ðŠÈ—ª‚É•\Œ»‚·‚é–Ú“I
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
