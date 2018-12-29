#ifndef MOTHER_H
#define MOTHER_H

#include"Field.h"
#include"Dot.h"
#include"Direction.h"
#include"GetPosNum.h"
#include <fstream>
#include <iomanip>

//Ppl�̐����ꏊ�݂̂������N���X
//OPD�ȊO�̃t�@�C�����͂������̎d���ɂȂ�
class Mother
{
public:
	Mother();
	~Mother();
	int Set(Field _root, Dot born, Direction _dir);
	Field GetRoot();
	Dot GetBornPos();
	Direction GetDir();
private:
	Field root;
	Dot bornPos;
	Direction dir;
};

int MomMngInitialize(int h,int w);
Mother MomMngGetNeg(int sensnum, bool isout);
Mother MomMngGetPos();

#endif // !MOTHER_H
