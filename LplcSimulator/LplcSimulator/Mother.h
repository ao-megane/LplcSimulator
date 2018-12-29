#ifndef MOTHER_H
#define MOTHER_H

#include"Field.h"
#include"Dot.h"
#include"GetPosNum.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//Ppl�̐����ꏊ�݂̂������N���X
//OPD�ȊO�̃t�@�C�����͂������̎d���ɂȂ�
class Mother
{
public:
	Mother();
	~Mother();
	int Set(Field _root, Dot born);
	int Set(string filename);
	int SetBornPos(Dot pos);
	Field GetRoot();
	Field* GetRootAd();
	Dot GetBornPos();
	int testDraw();
private:
	Field root;
	Dot bornPos;
};

int MomMngInitialize(int h,int w);
Mother MomMngGetNeg(int sensnum, bool isout);
Mother MomMngGetPos();

int testMomInitialize(int h,int w);
Mother GetMomtest();

#endif // !MOTHER_H
