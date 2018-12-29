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
Mother positive[5];//センサ番号は6，9，10，12，13

int MomMngInitialize(int h,int w) {//いろんな流出ルートを格納する
	string filename;	//たびたび変わるファイルネーム，使いまわしまくるので初期化を忘れないように
	string line;
	ifstream ifs;
	ofstream ofs;

	for (int i = 0; i < 19; i++) {
		sensor[19][0].GetRoot().Initialize(h, w);
		sensor[19][1].GetRoot().Initialize(h, w);
	}
	for (int i = 0; i < 5; i++) {
		positive[i].GetRoot().Initialize(h, w);
	}
	
	//各センサを通った時の移動ルートを格納
	//int range = 11;
	for (int i = 0; i < 19; i++) {
		filename = "mapdatas/roots/";
		//filename += to_string(range + 1);
		//filename += "/";
		filename += to_string(i + 1);
		filename += "in.csv";

		//cout << filename << endl;
		sensor[i][0].GetRoot().Set(filename);



		//filename = "mapdatas/roots/";
		////filename += to_string(range + 1);
		////filename += "/";
		//filename += to_string(i + 1);
		//filename += "out.csv";
		////cout << filename << endl;
		//ifs.open(filename.c_str());
		//if (!ifs) {
		//	cout << "ファイルオープンに失敗" << filename << endl;
		//}
		//j = 0; k = 0;
		//while (getline(ifs, line)) {
		//	vector<string> strvec = split(line, ',');
		//	for (k = 0; k < strvec.size(); k++) {
		//		//if (strvec.at(k) == "") out[i][j][k] = 0;
		//		//else out[i][j][k] = stoi(strvec.at(k));
		//		if (strvec.at(k) == "") sensor[i][1].GetRoot().SetValue(j, k, 0);
		//		else sensor[i][1].GetRoot().SetValue(j, k, stoi(strvec.at(k)));
		//	}
		//	j++;
		//}
		//ifs.close();
	}

	for (int i = 0; i < 5; i++) {

	}

	return 0;
}

Mother MomMngGetNeg(int sensnum, bool isout) {
	return sensor[sensnum][isout];
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

Mother test;
int testMomInitialize(int h, int w) {
	test.GetRootAd()->Initialize(h, w);
	//cout << test.GetRoot().GetField().size() << endl;
	//test.GetRootAd()->Set("mapdatas/pos/test.csv");
	test.Set("mapdatas/pos/test.csv");
	//cout << test.GetRoot().GetField().size() << ":" << test.GetRoot().GetField()[0].size();

	//test.GetRoot().testDraw();
	test.testDraw();
	return 0;
}
int Mother::testDraw() {
	test.GetRoot().testDraw();
	cout << "START:" << test.GetBornPos().Getx() << "," << test.GetBornPos().Gety() << endl;
	return 0;
}
Mother GetMomtest() {
	return test;
}