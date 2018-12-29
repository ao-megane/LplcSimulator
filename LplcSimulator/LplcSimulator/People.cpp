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
	//ここに関数まとめちまうか
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
	//nowposに接する4点のうち，前にいたとこpreposを除いて調べて，道が続いていればdirとかｔ一緒に更新
	if (Root.GetValue(nowPos.Getx(), nowPos.Gety() - 1)) {//上
		if (!prePos.isCollect(nowPos.Getx(), nowPos.Gety() - 1)) {//preposと不一致
			prePos = nowPos;
			nowPos.up();
			dir = UP;
			return 0;
		}
	}
	if (Root.GetValue(nowPos.Getx(), nowPos.Gety() + 1)) {//下
		if (!prePos.isCollect(nowPos.Getx(), nowPos.Gety() + 1)) {//preposと不一致
			prePos = nowPos;
			nowPos.down();
			dir = DOWN;
			return 0;
		}
	}
	if (Root.GetValue(nowPos.Getx() + 1, nowPos.Gety())) {//右
		if (!prePos.isCollect(nowPos.Getx() + 1, nowPos.Gety())) {//preposと不一致
			prePos = nowPos;
			nowPos.right();
			dir = RIGHT;
			return 0;
		}
	}
	if (Root.GetValue(nowPos.Getx() - 1, nowPos.Gety())) {//左
		if (!prePos.isCollect(nowPos.Getx() - 1, nowPos.Gety())) {//preposと不一致
			prePos = nowPos;
			nowPos.left();
			dir = LEFT;
			return 0;
		}
	}

	//道が続いてなかったら存在を消す
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
		if (!positive[i].GetisExist()) {//存在しなければ
			positive[i].Born(MomMngGetPos());
		}
	}
	return 0;
}