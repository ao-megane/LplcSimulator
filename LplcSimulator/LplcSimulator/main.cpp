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

	int posnum = 200;

	int posm[60] = { 0 };//分あたり何人流入しなければいけないか
	int poss[60] = { 0 };//秒あたり何人流入しなければいけないか
	int negm[19][2][60] = { 0 };//これはOPDまま //sensnum,in/out,m
	int negs[19][2][60] = { 0 };//sensnum,in/out,s

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

	cout << width << "," << height << endl;
	cout << start << "," << end << endl;

	/*------------初期化--------------*/
	SetRand();
	to60Initialize();
	MomMngInitialize(height,width);
	PplMngInitialize(height, width);
	//RTMngInitialize(height, width);

	cout << "Initialize_end" << endl;

	/*---------test--------------*/
	/*testMomInitialize(height,width);
	testPplMngInitialize(height, width);
	testRTInitialize(height, width);

	testPosMngBorn();

	for (int i = 0; i < 30; i++) {
		testRTUpdate(testPosGet());
		testPosMngUpdate();
	}*/

	/*----------本処理-------------*/
	int year = 2018;
	int month = 6;
	int date = 1;
	while (month == 6) {
		RTMngReset();
		if (aaa(year, month, date) == 0 || aaa(year, month, date) == 6) {
			cout << "holiday(non_count)" << ttos(year, month, date) << endl;
			tomorrow(&year, &month, &date);
			continue;
		}
		else {
			//cout << "平日(カウントしない)" << ttos(year, month, date) << endl;
			//tomorrow(&year, &month, &date);
			//continue;
		}

		filename = "opendatas/";
		filename += ttos(year, month, date);
		filename += ".csv";
		ifs.open(filename);	//センサID，yyyy/m/d, h:mm, in, out, in累計, out累計\n
		if (!ifs) {
			cout << "succes:" << filename << endl;
			tomorrow(&year, &month, &date);
			continue;
		}
		else {
			//cout << "failed:" << filename << endl;
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
				cout << "sencing" << strvec.at(2) << endl;

				//cout << stoi(strvec.at(3)) << "," << stoi(strvec.at(4)) << endl;

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
		//一日分終わったら
		/*for (int i = 0; i < 60; i++) {
			cout << negm[1][0][i] << "," << negm[1][1][i] << endl;
		}*/
		/*for (int i = 0; i < 19; i++) {
			cout << i + 1 << ":" << negm[i][0][0] << "," << negm[i][1][0] << endl;
		}*/
		scanf_s("%d", &i);
		tomorrow(&year, &month, &date);
	}//6月のループ


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