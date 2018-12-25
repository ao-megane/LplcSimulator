#pragma once
#include"Camera.h"
#include"Field.h"

class VSS
{
public:
	VSS();
	~VSS();

private:
	int x;//左上から
	int y;//左上から
	int r;//アクセス有効範囲
	Field nowPos;
};

VSS::VSS()
{
}

VSS::~VSS()
{
}