#pragma once
#include"Camera.h"
#include"Field.h"

class VSS
{
public:
	VSS();
	~VSS();

private:
	int x;//���ォ��
	int y;//���ォ��
	int r;//�A�N�Z�X�L���͈�
	Field nowPos;
};

VSS::VSS()
{
}

VSS::~VSS()
{
}