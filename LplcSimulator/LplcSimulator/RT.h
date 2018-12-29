#pragma once
#include"Camera.h"

class RT
{
public:
	RT();
	~RT();

private:
	int x;//左上から
	int y;//左上から
	int r;//アクセス有効範囲
	Camera cameras[2];//2で固定(in/out)
	Field ART;
};

RT::RT()
{
}

RT::~RT()
{
}