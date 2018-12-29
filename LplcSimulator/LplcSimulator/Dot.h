#ifndef DOT_H
#define DOT_H

class Dot {//fieldを簡略に表現する目的
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


