#include"Mother.h"

Mother::Mother()
{
}

Mother::~Mother()
{
}

int Mother::Set(Field _root,Dot born) {
	root = _root;
	bornPos = born;
	//dir = _dir;
	return 0;
}
int Mother::Set(string filename) {
	bornPos = root.Set(filename);
	//bornPos.Set(filename);
	return 0;
}

int Mother::SetBornPos(Dot pos) {
	bornPos = pos;
	return 0;
}
Field Mother::GetRoot() {
	return root;
}
Field* Mother::GetRootAd() {
	return &root;
}
Dot Mother::GetBornPos() {
	return bornPos;
}

Mother sensor[19][2];
Mother negative[19][2];
Mother positive[5];//センサ番号は6，9，10，12，13

int MomMngInitialize(int h,int w) {//いろんな流出ルートを格納する
	string filename;	//たびたび変わるファイルネーム，使いまわしまくるので初期化を忘れないように
	string line;
	ifstream ifs;
	ofstream ofs;

	for (int i = 0; i < 19; i++) {
		sensor[i][0].GetRootAd()->Initialize(h, w);
		sensor[i][1].GetRootAd()->Initialize(h, w);
		negative[i][0].GetRootAd()->Initialize(h, w);
		negative[i][1].GetRootAd()->Initialize(h, w);
	}
	for (int i = 0; i < 5; i++) {
		positive[i].GetRootAd()->Initialize(h, w);
	}
	
	//各センサを通った時の移動ルートを格納
	//int range = 11;
	for (int i = 0; i < 19; i++) {
		filename = "mapdatas/roots/";
		filename += to_string(i + 1);
		filename += "in.csv";
		//negative[i][0].GetRootAd()->Set(filename);
		negative[i][0].Set(filename);

		filename = "mapdatas/roots/";
		filename += to_string(i + 1);
		filename += "out.csv";
		//negative[i][1].GetRootAd()->Set(filename);
		negative[i][1].Set(filename);

		filename = "mapdatas/cameras/";
		filename += to_string(i + 1);
		filename += "in.csv";
		//sensor[i][0].GetRootAd()->Set(filename);
		sensor[i][0].Set(filename);

		filename = "mapdatas/cameras/";
		filename += to_string(i + 1);
		filename += "out.csv";
		//sensor[i][1].GetRootAd()->Set(filename);
		sensor[i][1].Set(filename);
	}

	for (int i = 0; i < 5; i++) {
		switch (i) {
		case 0:
			//positive[0].GetRootAd()->Set("mapdatas/pos/6.csv");
			positive[0].Set("mapdatas/pos/6.csv");
			break;
		case 1:
			//positive[0].GetRootAd()->Set("mapdatas/pos/9.csv");
			positive[1].Set("mapdatas/pos/9.csv");
			break;
		case 2:
			//positive[0].GetRootAd()->Set("mapdatas/pos/10.csv");
			positive[2].Set("mapdatas/pos/10.csv");
			break;
		case 3:
			//positive[0].GetRootAd()->Set("mapdatas/pos/12.csv");
			positive[3].Set("mapdatas/pos/12.csv");
			break;
		case 4:
			//positive[0].GetRootAd()->Set("mapdatas/pos/13.csv");
			positive[4].Set("mapdatas/pos/13.csv");
			break;
		default:
			cout << "MOMMNGINITIALIZE_ERROR!" << endl;
			break;
		}
	}

	return 0;
}

Mother MomMngGetNeg(int sensnum, bool isout) {
	return negative[sensnum][isout];
}
Mother MomMngGetPos() {
	int a = GetPosNum();
	//int a = 0;
	switch (a)
	{
	case 6:
		return positive[0];
		break;
	case 9:
		return positive[1];
		break;
	case 10:
		return positive[2];
		break;
	case 12:
		return positive[3];
		break;
	case 13:
		return positive[4];
		break;
	default:
		cout << "MomMngGetPos ERROR!!" << endl;
		break;
	}
}
Mother MomMngGetCamera(int sensornum, int isout) {
	return sensor[sensornum][isout];
}

Mother testppl;
Mother testcamera;
int testMomInitialize(int h, int w) {
	testppl.GetRootAd()->Initialize(h, w);
	testcamera.GetRootAd()->Initialize(h, w);
	//cout << test.GetRoot().GetField().size() << endl;
	//test.GetRootAd()->Set("mapdatas/pos/test.csv");
	testppl.Set("mapdatas/pos/test.csv");
	testcamera.Set("mapdatas/cameras/test.csv");
	//cout << test.GetRoot().GetField().size() << ":" << test.GetRoot().GetField()[0].size();

	//test.GetRoot().testDraw();
	//testppl.testDraw();
	//cout << "-----camera----" << endl;
	testcamera.testDraw();

	cout << endl;
	return 0;
}
int Mother::testDraw() {
	//testppl.GetRoot().testDraw();
	//cout << "START:" << testppl.GetBornPos().Getx() << "," << testppl.GetBornPos().Gety() << endl;
	root.testDraw();
	//Dotのx,yといつものx,yが逆なので注意
	cout << "START:" << bornPos.Getx() << "," << bornPos.Gety() << endl;
	return 0;
}
Mother GetMomtest() {
	return testppl;
}
Mother testMomGetCamera() {
	return testcamera;
}