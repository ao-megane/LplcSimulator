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
	return -1;
}