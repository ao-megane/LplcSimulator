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

	/*cout << "UP:" << Root.GetValue(nowPos.upDot()) << endl;
	cout << "DOWN:" << Root.GetValue(nowPos.downDot()) << endl;
	cout << "RIGHT:" << Root.GetValue(nowPos.rightDot()) << endl;
	cout << "LEFT:" << Root.GetValue(nowPos.leftDot()) << endl;*/

	if (Root.GetValue(nowPos.upDot()) == 1) {//上
		dir = UP;
		return 0;
	}
	if (Root.GetValue(nowPos.downDot()) == 1) {//下
		dir = DOWN;
		return 0;
	}
	if (Root.GetValue(nowPos.rightDot()) == 1) {//右
		dir = RIGHT;
		return 0;
	}
	if (Root.GetValue(nowPos.leftDot()) == 1) {//左
		dir = LEFT;
		return 0;
	}

	return -1;
}

bool People::GetisExist() {
	return isExist;
}
Dot People::GetNowPos() {
	return nowPos;
}
Field People::GetUpField(){
	return up;
}
Field People::GetDownField() {
	return down;
}
Field People::GetRightField() {
	return right;
}
Field People::GetLeftField() {
	return left;
}

int People::Update() {
	//nowposに接する4点のうち，道が続いていればdirとかと一緒に更新
	//引き返さないという前提がある

	up.SetAllZero();
	down.SetAllZero();
	right.SetAllZero();
	left.SetAllZero();

	if (Root.GetValue(nowPos.upDot()) == 1) {//上
		if (dir != DOWN) {
			prePos = nowPos;
			nowPos.up();
			dir = UP;
			up.SetValue(nowPos,1);
			return 0;
		}
	}
	if (Root.GetValue(nowPos.downDot()) == 1) {//下
		if (dir != UP) {
			prePos = nowPos;
			nowPos.down();
			dir = DOWN;
			down.SetValue(nowPos, 1);
			return 0;
		}
	}
	if (Root.GetValue(nowPos.rightDot()) == 1) {//右
		if (dir != LEFT) {
			prePos = nowPos;
			nowPos.right();
			dir = RIGHT;
			right.SetValue(nowPos, 1);
			return 0;
		}
	}
	if (Root.GetValue(nowPos.leftDot()) == 1) {//左
		if (dir != RIGHT) {
			prePos = nowPos;
			nowPos.left();
			dir = LEFT;
			left.SetValue(nowPos, 1);
			return 0;
		}
	}

	//道が続いてなかったら存在を消す
	isExist = false;
	dir = DEFAULT;
	prePos.Initialize();
	nowPos.Initialize();
	//cout << "----------------------------DELETE!!" << endl;
	return -1;
}

int People::testDraw() {
	cout << "PPLTEST" << endl;
	//Root.testDraw();
	//cout << "NOWPOS:" << nowPos.Getx() << "," << nowPos.Gety() << endl;
	if (!isExist) {
		cout << "nonExist!" << endl;
		return 0;
	}
	for (int i = 0; i < 10; i++) {//h
		for (int j = 0; j < 10; j++) {//w
			if (nowPos.GetxtoO() == i && nowPos.GetytoO() == j) {
				cout << Root.GetField()[i][j] + 1 << ",";
			}
			else {
				cout << Root.GetField()[i][j] << ",";
			}
		}
		cout << endl;
	}
	cout << "DIRECTION:";
	switch (dir)
	{
	case UP:
		cout << "UP" << endl;
		break;
	case DOWN:
		cout << "DOWN" << endl;
		break;
	case RIGHT:
		cout << "RIGHT" << endl;
		break;
	case LEFT:
		cout << "LEFT" << endl;
		break;
	case DEFAULT:
		cout << "DEFAULT" << endl;
		break;
	default:
		break;
	}
	return 0;
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
int NegMngBorn(int sensornum,bool isout) {
	for (int i = 0; i < NEG_NUM; i++) {
		if (!negative[i].GetisExist()) {//存在しなければ
			negative[i].Born(MomMngGetNeg(sensornum, isout));
		}
	}
	return 0;
}

int PosMngUpdate() {
	for (int i = 0; i < POS_NUM; i++) {
		if (positive[i].GetisExist()) {//存在すれば
			positive[i].Update();
		}
	}
	return 0;
}
int NegMngUpdate() {
	for (int i = 0; i < NEG_NUM; i++) {
		if (negative[i].GetisExist()) {//存在すれば
			negative[i].Update();
		}
	}
	return 0;
}
int PplMngUpdate() {
	PosMngUpdate();
	NegMngUpdate();
	return 0;
}

People test;
int testPplMngInitialize(int h,int w) {
	test.Initialize(h, w, 1);

	//test.testDraw();

	return 0;
}
int testPosMngBorn() {
	test.Born(GetMomtest());
	test.testDraw();
	return 0;
}
int testPosMngUpdate() {
	test.Update();
	test.testDraw();
	return 0;
}
People* testPosGet() {
	return &test;
}