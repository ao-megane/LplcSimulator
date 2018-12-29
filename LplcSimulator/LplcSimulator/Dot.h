#ifndef DOT_H
#define DOT_H

class Dot {//field‚ğŠÈ—ª‚É•\Œ»‚·‚é–Ú“I,vector‚¾‚Æ‰º‰E‚Ì‡‚Å‚â‚è‚Ã‚ç‚¢
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


