#include <iostream>
#include <time.h>
#include "Field.h"
#include "Camera.h"
#include "date.h"
#include "GetPosNum.h"
#include "Mother.h"
#include "People.h"

int main() {
	/*------------変数定義--------------*/
	string line;
	string start;	//計測開始時刻	//hh:mmという形式なので注意
	string end;		//計測終了時刻
	string filename;	//たびたび変わるファイルネーム，使いまわしまくるので初期化を忘れないように
	int year;
	int month;
	int date;
	int i = 0;
	int width = 0;//マップの広さ(全Fieldクラスで共通)
	int height = 0;//マップの広さ(全Fieldクラスで共通)

	bool isTracking = false;
	double ratio[30] = { 0 };

	int holidaynum = 9;
	int workdaynum = 21;

	

	/*------------入力--------------*/
	//cout << "----------------------------" << endl;
	ifstream ifs;
	ofstream ofs;
	ifs.open("mapdatas/map.txt");	//マップの広さとか
	if (!ifs) {
		cout << "ファイルオープンに失敗" << "mapdatas/map.txt" << endl;
	}

	if (getline(ifs, line)) {
		vector<string> strvec = split(line, ',');
		width = stoi(strvec.at(0));
	}
	if (getline(ifs, line)) {
		vector<string> strvec = split(line, ',');
		height = stoi(strvec.at(0));
	}
	if (getline(ifs, line)) {
		vector<string> strvec = split(line, ',');
		start = strvec.at(0);
	}
	if (getline(ifs, line)) {
		vector<string> strvec = split(line, ',');
		end = strvec.at(0);
	}
	/*if (getline(ifs, line)) {
		vector<string> strvec = split(line, ',');
		posnum = stoi(strvec.at(0));
	}
	*/
	ifs.close();

	/*------------初期化--------------*/
	SetRand();
	/*---------test--------------*/
	testMomInitialize(height,width);
	testPplMngInitialize(height, width);

	testPosMngBorn();

	for (int i = 0; i < 30; i++) {
		testPosMngUpdate();
	}





	/*-----------test-------------*/
	//MomMngInitialize(height, width);
	//PplMngInitialize(height, width);

	//posファイル読み込み&格納
	//for (int i = 0; i < 19; i++) {
	//	filename = "mapdatas/allmap/pos/";
	//	filename += to_string(i + 1);
	//	filename += ".csv";
	//	cout << filename << endl;
	//	ifs.open(filename.c_str());
	//	if (!ifs) {
	//		cout << "ファイルオープンに失敗" << filename << endl;
	//		for (int h = 0; h < height; h++) {
	//			for (int w = 0; w < width; w++) {
	//				positive[i][h][w] = 0;
	//			}
	//		}
	//		continue;
	//	}
	//	else {
	//		int j = 0, k = 0;
	//		while (getline(ifs, line)) {
	//			vector<string> strvec = split(line, ',');
	//			for (k = 0; k < strvec.size(); k++) {
	//				if (strvec.at(k) == "") positive[i][j][k] = 0;
	//				else positive[i][j][k] = stoi(strvec.at(k));
	//			}
	//			j++;
	//		}
	//	}
	//	ifs.close();
	//	//cout << i << endl;
	//}

	//センサ有効範囲についてのforループ
	//cout << "----------------------------" << endl;
	int range = 11;
	for (int t = 0; t < 1; t++) {
		range = 11;
		

		//センサ初期化
		/*for (int i = 0; i < 19; i++) {
			sensor[i].Initialize();
		}*/

		//マップ初期化
		/*for (int i = 0; i < map.size(); ++i) {
			for (int j = 0; j < map[i].size(); ++j) {
				map[i][j] = 0;
			}
		}*/
		//cout << "----------------------------" << endl;

		//日付初期化
		year = 2018;
		month = 6;
		date = 1;
		int data[19 * 2] = { 0 };
		//30日分のtime時をまとめて処理
		//for (int time = 5; time < 24; time++) {
		year = 2018;
		month = 6;
		date = 1;
		//センサ初期化
		/*for (int i = 0; i < 19; i++) {
			sensor[i].Initialize();
		}*/
		for (int count = 0; count < 30; count++) {//日付
			if (aaa(year, month, date) == 0 || aaa(year, month, date) == 6) {
				cout << "休日(カウントしない)" << ttos(year, month, date) << endl;
				tomorrow(&year, &month, &date);
				continue;
			}
			else {
				//cout << "平日(カウントしない)" << ttos(year, month, date) << endl;
				//tomorrow(&year, &month, &date);
				//continue;
			}
			//cout << time << ":";
			cout << date << ":";
			//cout << count << ":" << endl;
			//マップ初期化
			/*for (int i = 0; i < map.size(); ++i) {
				for (int j = 0; j < map[i].size(); ++j) {
					map[i][j] = 0;
				}
			}*/

			filename = "opendatas/";
			filename += ttos(year, month, date);
			filename += ".csv";
			ifs.open(filename);	//センサID，yyyy/m/d, h:mm, in, out, in累計, out累計\n
			if (!ifs) {
				cout << "ファイルオープンに失敗" << filename << endl;
				tomorrow(&year, &month, &date);
				continue;
			}
			else {
				//cout << "ファイルオープンに成功" << filename << endl;
				//count++;
			}
			i = 0;
			while (getline(ifs, line)) {//オープンデータ内のループ
				vector<string> strvec = split(line, ',');//データ一行ゲット
														 //if (strvec.at(2) == ttos(start,0)) {//データの時間評価
				if (strvec.at(2) == start) {
					isTracking = true;
				}
				if (isTracking) {
					//if (strvec.at(2) == ttos(end,0)) {
					if (strvec.at(2) == end) {
						isTracking = false;
					}
				}
				if (isTracking) {
					//cout << "計測中" ;

					//cout << strvec.at(2) << endl;
					//センサ更新
					/*for (int h = 0; h < height; h++) {
						for (int w = 0; w < width; w++) {
							sensor[i].nAdd(stoi(strvec.at(3)) * in[i][h][w], stoi(strvec.at(4))*out[i][h][w]);
						}
					}*/

					if (i < 18) {
						i++;
					}
					else {//１周期終了，マップ更新
						//cout << "動作中！！" << endl;
						//for (int id = 0; id < 19; id++) {
						//	for (int h = 0; h < height; h++) {
						//		for (int w = 0; w < width; w++) {//mapに書き込む
						//			map[h][w] += in[id][h][w] * sensor[id].GetnIn();
						//			map[h][w] += out[id][h][w] * sensor[id].GetnOut();
						//			data[id * 2 + 0] += in[id][h][w] * sensor[id].GetnIn();
						//			data[id * 2 + 1] += out[id][h][w] * sensor[id].GetnOut();
						//		}
						//	}
						//}
						i = 0;
					}
				}
				else {
					//cout << strvec.at(2) << endl;
				}
			}
			ifs.close();
			//cout << date << endl;
			tomorrow(&year, &month, &date);
		}//30日終わり

		 //対象者について
		//for (int pos = 0; pos <= 200; pos += 10) {
		//	//int posnum = 1000;	//平日で割られるので，実質50人くらい
		//	cout << pos << endl;
		//	int posnum = workdaynum * pos;
		//	int num;
		//	for (int i = 0; i < 30; i++) {//30倍回して
		//		for (int t = 0; t < posnum; t++) {//人数
		//			num = GetPosNum();//n人目のルート決定
		//			for (int id = 0; id < 19; id++) {//センサ全部でチェック
		//				for (int h = 0; h < height; h++) {
		//					for (int w = 0; w < width; w++) {
		//						if (id == 9 || id == 11) {
		//							sensor[id].pAdd(0, positive[num - 1][h][w] * out[id][h][w]);
		//							continue;
		//						}
		//						if (id == 7 || id == 13) {
		//							sensor[id].pAdd(positive[num - 1][h][w] * in[id][h][w], 0);
		//							continue;
		//						}
		//						sensor[id].pAdd(positive[num - 1][h][w] * in[id][h][w], positive[num - 1][h][w] * out[id][h][w]);
		//					}
		//				}
		//			}
		//		}
		//	}
		//	for (int id = 0; id < 19; id++) {//平均にする
		//		sensor[id].pDivision(30.0);
		//	}

		//	int negdata = 0;
		//	int posdata = 0;
		//	for (int i = 0; i < 19; i++) {
		//		negdata += (sensor[i].GetSumnIn() + sensor[i].GetSumnOut());
		//		posdata += (sensor[i].GetSumpIn() + sensor[i].GetSumpOut());
		//	}

		//	ratio[pos / 10] = (double)(negdata) / (posdata + negdata);
		//}
	}//range終わり

	filename = "results/add_positive_pertime/result.csv";
	ofs.open(filename, ios::trunc);
	for (int pos = 0; pos <= 200; pos += 10) {
		ofs << pos << "," << fixed << setprecision(5) << (double)ratio[pos / 10] << endl;
	}
	ofs.close();

	int a;
	scanf_s("%d", &a);

	return 0;
}