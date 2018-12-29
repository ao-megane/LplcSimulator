#include"Mother.h"

Mother::Mother()
{
}

Mother::~Mother()
{
}

int Mother::Set(Field _root,Dot born,Direction _dir) {
	root = _root;
	bornPos = born;
	dir = _dir;
	return 0;
}
Field Mother::GetRoot() {
	return root;
}
Dot Mother::GetBornPos() {
	return bornPos;
}
Direction Mother::GetDir() {
	return dir;
}

Mother sensor[19][2];
Mother positive[5];

int MomMngInitialize(int h,int w) {
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

	//各センサに有効範囲を格納(センサについてのforループ)
	//int range = 11;
	for (int i = 0; i < 19; i++) {
		filename = "mapdatas/cameras/";
		//filename += to_string(range + 1);
		//filename += "/";
		filename += to_string(i + 1);
		filename += "in.csv";

		//cout << filename << endl;
		ifs.open(filename.c_str());
		if (!ifs) {
			cout << "ファイルオープンに失敗" << filename << endl;
		}

		int j = 0, k = 0;
		while (getline(ifs, line)) {
			vector<string> strvec = split(line, ',');
			for (k = 0; k < strvec.size(); k++) {
				if (strvec.at(k) == "") sensor[i][0].GetRoot().SetValue(j, k, 0);
				else sensor[i][0].GetRoot().SetValue(j, k, stoi(strvec.at(k)));
			}
			j++;
		}
		ifs.close();

		filename = "mapdatas/cameras/";
		//filename += to_string(range + 1);
		//filename += "/";
		filename += to_string(i + 1);
		filename += "out.csv";
		//cout << filename << endl;
		ifs.open(filename.c_str());
		if (!ifs) {
			cout << "ファイルオープンに失敗" << filename << endl;
		}
		j = 0; k = 0;
		while (getline(ifs, line)) {
			vector<string> strvec = split(line, ',');
			for (k = 0; k < strvec.size(); k++) {
				//if (strvec.at(k) == "") out[i][j][k] = 0;
				//else out[i][j][k] = stoi(strvec.at(k));
				if (strvec.at(k) == "") sensor[i][1].GetRoot().SetValue(j, k, 0);
				else sensor[i][1].GetRoot().SetValue(j, k, stoi(strvec.at(k)));
			}
			j++;
		}
		ifs.close();
	}
	return 0;
}