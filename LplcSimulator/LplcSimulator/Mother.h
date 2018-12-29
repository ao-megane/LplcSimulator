#ifndef MOTHER_H
#define MOTHER_H

#include"Field.h"
#include"Dot.h"
#include"Direction.h"
#include"GetPosNum.h"
#include <fstream>
#include <iomanip>

//Pplの生成場所のみを扱うクラス
//OPD以外のファイル入力もこいつの仕事になる
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
