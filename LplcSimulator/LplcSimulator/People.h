#ifndef PEOPLE_H
#define PEOPLE_H

#include"Field.h"
#include"Direction.h"
#include"Dot.h"
#include"Value.h"
#include"Mother.h"
#include<iostream>

using namespace std;

class People
{
public:
	People();
	~People();
	int Initialize(int h,int w,bool isPos);
	int Born(Field root, Dot bornPos, Direction _dir);
	int Born(Mother mother);
	//int Born(Mother* mother);
	int Update();
	bool GetisExist();
	Dot GetNowPos();
	Field* GetUpFieldAd();
	Field* GetDownFieldAd();
	Field* GetRightFieldAd();
	Field* GetLeftFieldAd();
	int testDraw();

private:
	Dot nowPos;
	Dot prePos;
	Field Root;
	//Field* Root;
	Field up;
	Field down;
	Field right;
	Field left;
	Direction dir;//����H
	bool isPositive;
	bool isExist;
};

int PosMngInitialize(int h, int w);
int PosMngBorn();
int PosMngUpdate();
People* PosMngGet();

int NegMngInitialize(int h, int w);
int NegMngBorn(int sensornum,bool isout);
int NegMngUpdate();
People* NegMngGet();
int NegNum();

int PplMngInitialize(int h, int w);
int PplMngUpdate();

int testPplMngInitialize(int h, int w);
int testPosMngBorn();
int testPosMngUpdate();
People* testPosGetAd();

#endif // !PEOPLE_H