#include"People.h"

People::People() {
	nowPos.Initialize();
	prePos.Initialize();
	dir = DEFAULT;
	isExist = false;
}

People::~People() {
}

int People::Initialize(int h,int w,bool isPos) {
	nowPos.Initialize();
	prePos.Initialize();
	Root.Initialize(h, w);
	up.Initialize(h, w);
	down.Initialize(h, w);
	right.Initialize(h, w);
	left.Initialize(h, w);
	dir = DEFAULT;
	isPositive = isPos;
	isExist = false;
	return 0;
}

int People::Set(Field rot, Dot bornPos) {
	Root = rot;
	nowPos = bornPos;
	return 0;
}

int People::Update() {
	//nowpos�ɐڂ���4�_�̂����C�O�ɂ����Ƃ�prepos�������Ē��ׂāC���������Ă����dir�Ƃ����ꏏ�ɍX�V
	if (Root.GetValue(nowPos.Getx(), nowPos.Gety() - 1)) {//��
		if (!prePos.isCollect(nowPos.Getx(), nowPos.Gety() - 1)) {//prepos�ƕs��v
			prePos = nowPos;
			nowPos.up();
			dir = UP;
			return 0;
		}
	}
	if (Root.GetValue(nowPos.Getx(), nowPos.Gety() + 1)) {//��
		if (!prePos.isCollect(nowPos.Getx(), nowPos.Gety() + 1)) {//prepos�ƕs��v
			prePos = nowPos;
			nowPos.down();
			dir = DOWN;
			return 0;
		}
	}
	if (Root.GetValue(nowPos.Getx() + 1, nowPos.Gety())) {//�E
		if (!prePos.isCollect(nowPos.Getx() + 1, nowPos.Gety())) {//prepos�ƕs��v
			prePos = nowPos;
			nowPos.right();
			dir = RIGHT;
			return 0;
		}
	}
	if (Root.GetValue(nowPos.Getx() - 1, nowPos.Gety())) {//��
		if (!prePos.isCollect(nowPos.Getx() - 1, nowPos.Gety())) {//prepos�ƕs��v
			prePos = nowPos;
			nowPos.left();
			dir = LEFT;
			return 0;
		}
	}

	//���������ĂȂ������瑶�݂�����
	isExist = false;
	dir = DEFAULT;
	return -1;
}