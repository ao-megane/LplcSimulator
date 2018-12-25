#pragma once
#include"Field.h"
#include"Direction.h"

class People
{
public:
	People();
	~People();
	int Initialize();

private:
	Field nowPos;
	Field prePos;
	Field Root;
	Field up;
	Field down;
	Field right;
	Field left;
	Direction dir;//Ç¢ÇÈÅH
	int bornSensorNum;
	bool isPositive;
	bool isExist;
};

People::People()
{
}

People::~People()
{
}

int PosMngInitialize();
int PosMngUpdate();

int NegMngInitialize();
int NegMngUpdate();
