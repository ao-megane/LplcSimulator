#pragma once
#include"Camera.h"

class RT
{
public:
	RT();
	~RT();

private:
	int x;//���ォ��
	int y;//���ォ��
	int r;//�A�N�Z�X�L���͈�
	Camera cameras[2];//2�ŌŒ�(in/out)
	Field ART;
};

RT::RT()
{
}

RT::~RT()
{
}