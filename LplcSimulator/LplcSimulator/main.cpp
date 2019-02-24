#include <iostream>
#include <time.h>
#include "Field.h"
#include "Camera.h"
#include "date.h"
#include "GetPosNum.h"
#include "Mother.h"
#include "People.h"
#include "RT.h"
#include "to60.h"

int main() {
	/*------------変数定義--------------*/
	string line;
	string start;	//計測開始時刻	//hh:mmという形式なので注意
	string end;		//計測終了時刻
	string filename;	//たびたび変わるファイルネーム，使いまわしまくるので初期化を忘れないように
	
	int i = 0;
	int count = 0;	//60まで(OPD入力回数を測る子)
	int width = 0;	//マップの広さ(全Fieldクラスで共通)
	int height = 0;	//マップの広さ(全Fieldクラスで共通)

	int posnum = 1;//0～200(50刻み)1 100 200 で出す

	int posm[60] = { 0 };//分あたり何人流入しなければいけないか
	int poss[60] = { 0 };//秒あたり何人流入しなければいけないか
	int negm[19][2][60] = { 0 };//これはOPDまま //sensnum,in/out,m
	int negs[19][2][60] = { 0 };//sensnum,in/out,s

	bool isTracking = false;

	int holidaynum = 9;
	int workdaynum = 21;

	/*------------入力--------------*/
	//cout << "----------------------------" << endl;
	ifstream ifs;
	ofstream ofs;
	ifs.open("mapdatas/map.txt");	//マップの広さとか
	if (!ifs) {
		cout << "failed:" << "mapdatas/map.txt" << endl;
	}
	else {
		cout << "succes:" << "mapdatas/map.txt" << endl;
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

	cout << width << "," << height << endl;
	cout << start << "," << end << endl;

	/*------------初期化--------------*/
	SetRand();
	to60Initialize();
	MomMngInitialize(height,width);
	PplMngInitialize(height, width);
	RTMngInitialize(height, width);
	cout << "Initialize_end" << endl;

	/*---------test--------------*/
	/*testMomInitialize(height,width);
	testPplMngInitialize(height, width);
	testRTInitialize(height, width);

	testPosMngBorn();
	cout << "test" << endl;
	for (int i = 0; i < 30; i++) {
		testRTUpdate(testPosGetAd());
		testPosMngUpdate();
	}

	scanf_s("%d", &i);*/

	/*----------本処理-------------*/
	double ratio[9] = { 0 };
	double cratio[9] = { 0 };
	for (posnum = 0; posnum <= 200; posnum += 25) {
		RTMngReset();
		int year = 2018;
		int month = 6;
		int date = 1;

		if (posnum == 0) {
			to60(1, posm);
		}
		else {
			to60(posnum, posm);
		}

		while (month == 6 /*&& date == 1*/) {//一か月分のループ
		//while(date == 1){//一日だけ
			//RTMngReset();
			//cout << date << endl;
			if (aaa(year, month, date) == 0 || aaa(year, month, date) == 6) {
				cout << "holiday(non_count)" << ttos(year, month, date) << endl;
				tomorrow(&year, &month, &date);
				continue;
			}
			else {
				//cout << "workday(non_count)" << ttos(year, month, date) << endl;
				//tomorrow(&year, &month, &date);
				//continue;
			}

			filename = "opendatas/";
			filename += ttos(year, month, date);
			filename += ".csv";
			//cout << posnum << endl;
			ifs.open(filename.c_str());	//センサID，yyyy/m/d, h:mm, in, out, in累計, out累計\n
			if (!ifs) {
				cout << "failed:" << filename << endl;
				tomorrow(&year, &month, &date);
				continue;
			}
			else {
				cout << "succes:" << filename << endl;
				//count++;
			}

			i = 0;
			count = 0;
			while (getline(ifs, line)) {//オープンデータ内のループ,一日分のループ
				vector<string> strvec = split(line, ',');//データ一行ゲット
				//cout << start << ":" << strvec.at(2) << endl;
				if (strvec.at(2) == start) {
					isTracking = true;
				}
				if (isTracking) {
					if (strvec.at(2) == end) {
						isTracking = false;
					}
				}

				if (isTracking) {
					//cout << "storing" << strvec.at(2) << endl;

					negm[i][0][count] = stoi(strvec.at(3));
					negm[i][1][count] = stoi(strvec.at(4));

					if (i < 18) {
						i++;
					}
					else {//１周期終了
						i = 0;
						count++;
					}
					if (count > 60) {
						cout << "error_more60datas" << endl;
					}
				}
				else {
					//cout << strvec.at(2) << endl;
				}

			}
			//一日分の入力終わったら
			ifs.close();
			//cout << "end_input" << endl;

			/*cout << "test" << endl;
			for (int m = 0; m < 60; m++) {
				cout << negm[10][0][m] << endl;
			}*/

			for (int m = 0; m < 60; m++) {//一分毎のループ
				cout << "posnum:" << posnum << "  minuts:" << m << endl;
				//cout << "pos:" << posm[m] << endl;
				to60(posm[m], poss);//分のデータを秒毎に変換
				//cout << "posend" << endl;
				for (int num = 0; num < 19; num++) {//分のデータを秒毎に変換
					to60(negm[num][0][m], negs[num][0]);
					to60(negm[num][1][m], negs[num][1]);
				}
				for (int s = 0; s < 60; s++) {//一秒毎のループ
					//cout << "sec:" << s << endl;
					for (int i = 0; i < poss[s]; i++) {//指定回対象者を生む
						//cout << "PosBorn" << endl;
						//scanf_s("%d", &i);
						PosMngBorn();
					}
					for (int num = 0; num < 19; num++) {//指定回非対象者を生む
						for (int i = 0; i < negs[num][0][s]; i++) {
							NegMngBorn(num, 0);
						}
						for (int i = 0; i < negs[num][1][s]; i++) {
							NegMngBorn(num, 1);
						}
					}
					RTMngUpdate(PosMngGet(), NegMngGet());//生まれた瞬間を渡す
					PplMngUpdate();//渡してから進む

				}
				//RTMngtestDraw();
			}

			/*for (int i = 0; i < 60; i++) {
				cout << negm[1][0][i] << "," << negm[1][1][i] << endl;
			}*/
			/*for (int i = 0; i < 19; i++) {
				cout << i + 1 << ":" << negm[i][0][0] << "," << negm[i][1][0] << endl;
			}*/
			//scanf_s("%d", &i);
			tomorrow(&year, &month, &date);
		}//6月のループ

		//RTMngOutput("result.csv");
		ratio[posnum / 25] = RTMngGetRatio();
		cratio[posnum / 25] = CloudRatio();
		//break;//1だけでテスト
	}

	filename = "result.csv";
	ofs.open(filename.c_str(), ios::trunc);
	ofs << 1 << "," << ratio[0] << "," << cratio[0] << endl;
	for (int i = 1; i < 9;i++) {
		ofs << i*25 << "," << fixed << setprecision(5) << (double)ratio[i] << "," << (double)cratio[i] << endl;
	}
	ofs.close();

	//int a;
	//scanf_s("%d", &a);

	return 0;
}