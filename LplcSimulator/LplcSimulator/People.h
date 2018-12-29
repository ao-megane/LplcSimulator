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
	int Set(Field root, Dot bornPos, Direction _dir);
	//int Set(SensorBorn a);//��̎O���܂Ƃ߂��N���X�������Ă��悢����
	int Update();

private:
	Dot nowPos;
	Dot prePos;
	Field Root;
	Field up;
	Field down;
	Field right;
	Field left;
	Direction dir;//����H
	bool isPositive;
	bool isExist;
};

int PosMngInitialize();
int PosMngUpdate();

int NegMngInitialize();
int NegMngUpdate();


#endif // !PEOPLE_H