#pragma once
#include"VSS.h"

class RT
{
public:
	RT();
	~RT();

private:
	int x;//���ォ��
	int y;//���ォ��
	int r;//�A�N�Z�X�L���͈�
	VSS vss[3];//�ő�3(�V���~�l���C���C�R���R�[�X)
	Field ART;
};

RT::RT()
{
}

RT::~RT()
{
}