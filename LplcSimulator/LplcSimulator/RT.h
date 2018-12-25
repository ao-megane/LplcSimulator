#pragma once
#include"VSS.h"

class RT
{
public:
	RT();
	~RT();

private:
	int x;//左上から
	int y;//左上から
	int r;//アクセス有効範囲
	VSS vss[3];//最大3(シャミネ西，東，コンコース)
	Field ART;
};

RT::RT()
{
}

RT::~RT()
{
}