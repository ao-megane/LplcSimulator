#ifndef DOT_H
#define DOT_H

class Dot {//field���ȗ��ɕ\������ړI
public:
	Dot();
	~Dot();
	int Initialize();
	int up();
	int right();
	int left();
	int down();
	int Getx();
	int Gety();
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


