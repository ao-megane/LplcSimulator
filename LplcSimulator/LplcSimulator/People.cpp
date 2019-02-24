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
	return 0;
}
int People::Born(Mother mother) {
	isExist = true;
	Root = mother.GetRoot();
	nowPos = mother.GetBornPos();
	//nowPos.testDraw();
	//nowPos.testDraw();

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

	//int a;
	cout << "ppl_born_dir_error!" << endl;
	cout << "UP:" << Root.GetValue(nowPos.upDot()) << endl;
	cout << "DOWN:" << Root.GetValue(nowPos.downDot()) << endl;
	cout << "RIGHT:" << Root.GetValue(nowPos.rightDot()) << endl;
	cout << "LEFT:" << Root.GetValue(nowPos.leftDot()) << endl;
	//scanf_s("%d", &a);
	return -1;
}

bool People::GetisExist() {
	return isExist;
}
Dot People::GetNowPos() {
	return nowPos;
}
Field* People::GetUpFieldAd(){
	return &up;
}
Field* People::GetDownFieldAd() {
	return &down;
}
Field* People::GetRightFieldAd() {
	return &right;
}
Field* People::GetLeftFieldAd() {
	return &left;
}

int People::Update() {
	//nowposに接する4点のうち，道が続いていればdirとかと一緒に更新
	//引き返さないという前提がある
	up.SetAllZero();
	down.SetAllZero();
	right.SetAllZero();
	left.SetAllZero();

	/*cout << "UP:" << Root.GetValue(nowPos.upDot()) << endl;
	cout << "DOWN:" << Root.GetValue(nowPos.downDot()) << endl;
	cout << "RIGHT:" << Root.GetValue(nowPos.rightDot()) << endl;
	cout << "LEFT:" << Root.GetValue(nowPos.leftDot()) << endl;*/

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

	/*int a;
	cout << "ppl_update_dir_error!" << endl;
	cout << "UP:" << Root.GetValue(nowPos.upDot()) << endl;
	cout << "DOWN:" << Root.GetValue(nowPos.downDot()) << endl;
	cout << "RIGHT:" << Root.GetValue(nowPos.rightDot()) << endl;
	cout << "LEFT:" << Root.GetValue(nowPos.leftDot()) << endl;*/
	//scanf_s("%d", &a);

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
	cout << "NOWPOS:" << nowPos.Getx() << "," << nowPos.Gety() << endl;
	if (!isExist) {
		cout << "nonExist!" << endl;
		return 0;
	}
	//for (int i = 0; i < 10; i++) {//h
	//	for (int j = 0; j < 10; j++) {//w
	//		if (nowPos.Getx() == i && nowPos.Gety() == j) {
	//			cout << Root.GetField()[i][j] + 1 << ",";
	//		}
	//		else {
	//			cout << Root.GetField()[i][j] << ",";
	//		}
	//	}
	//	cout << endl;
	//}
	//Root.eachtestDraw();

	cout << "P_DIR:";
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
	/*for (int i = 0; i < POS_NUM; i++) {
		positive[i].Initialize(h, w, true);
	}
	for (int i = 0; i < NEG_NUM; i++) {
		negative[i].Initialize(h, w, false);
	}*/
	PosMngInitialize(h, w);
	NegMngInitialize(h, w);
	return 0;
}

int PosMngBorn() {
	for (int i = 0; i < POS_NUM; i++) {
		if (!positive[i].GetisExist()) {//存在しなければ
			positive[i].Born(MomMngGetPos());
			//positive[i].GetNowPos().testDraw();
			return 1;
		}
	}
	cout << "POS_BORN_ERROR!" << endl;
	return 0;
}
int NegMngBorn(int sensornum,bool isout) {
	//cout << "neg_born" << endl;
	for (int i = 0; i < NEG_NUM; i++) {
		if (!negative[i].GetisExist()) {//存在しなければ
			negative[i].Born(MomMngGetNeg(sensornum, isout));
			//cout << "NEG_BORN : " << i << endl;
			return 1;
		}
	}
	cout << "NEG_BORN_ERROR!" << endl;
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
People* PosMngGet() {
	return positive;
}
People* NegMngGet() {
	return negative;
}
int NegNum() {
	int num = 0;
	for (int i = 0; i < NEG_NUM; i++) {
		if (negative[i].GetisExist()) {
			num++;
		}
	}
	return num;
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
People* testPosGetAd() {
	return &test;
}