#ifndef PEOPLE_H
#define PEOPLE_H

#include"Field.h"
#include"Direction.h"
#include"Dot.h"

class People
{
public:
	People();
	~People();
	int Initialize(int h,int w,bool isPos);
	int Set(Field root, Dot bornPos);
	int Update();

private:
	Dot nowPos;
	Dot prePos;
	Field Root;
	Field up;
	Field down;
	Field right;
	Field left;
	Direction dir;//Ç¢ÇÈÅH
	bool isPositive;
	bool isExist;
};

int PosMngInitialize();
int PosMngUpdate();

int NegMngInitialize();
int NegMngUpdate();


#endif // !PEOPLE_H