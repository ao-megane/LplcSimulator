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

int People::Born(Field _root, Dot bornPos,Direction _dir) {
	isExist = true;
	Root = _root;
	nowPos = bornPos;
	dir = _dir;
	//�����Ɋ֐��܂Ƃ߂��܂���
	return 0;
}
int People::Born(Mother mother) {
	isExist = true;
	Root = mother.GetRoot();
	nowPos = mother.GetBornPos();
	dir = mother.GetDir();
	return -1;
}

bool People::GetisExist() {
	return isExist;
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
	prePos.Initialize();
	nowPos.Initialize();
	return -1;
}

People positive[POS_NUM];
People negative[NEG_NUM];

int PosMngInitialize(int h,int w) {
	for (int i = 0; i < POS_NUM; i++) {
		positive[i].Initialize(h, w, true);
	}
	return 0;
}
int NegMngInitialize(int h, int w) {
	for (int i = 0; i < NEG_NUM; i++) {
		negative[i].Initialize(h, w, false);
	}
	return 0;
}
int PplMngInitialize(int h, int w) {
	for (int i = 0; i < POS_NUM; i++) {
		positive[i].Initialize(h, w, true);
	}
	for (int i = 0; i < NEG_NUM; i++) {
		negative[i].Initialize(h, w, false);
	}
	return 0;
}

int PosMngBorn() {
	for (int i = 0; i < POS_NUM; i++) {
		if (!positive[i].GetisExist()) {//���݂��Ȃ����
			positive[i].Born(MomMngGetPos());
		}
	}
	return 0;
}