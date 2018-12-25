#pragma once
#include"Field.h"
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