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
	/*------------�ϐ���`--------------*/
	string line;
	string start;	//�v���J�n����	//hh:mm�Ƃ����`���Ȃ̂Œ���
	string end;		//�v���I������
	string filename;	//���т��ѕς��t�@�C���l�[���C�g���܂킵�܂���̂ŏ�������Y��Ȃ��悤��
	
	int i = 0;
	int count = 0;	//60�܂�(OPD���͉񐔂𑪂�q)
	int width = 0;	//�}�b�v�̍L��(�SField�N���X�ŋ���)
	int height = 0;	//�}�b�v�̍L��(�SField�N���X�ŋ���)

	int posnum = 1;//0�`200(50����)1 100 200 �ŏo��

	int posm[60] = { 0 };//�������艽�l�������Ȃ���΂����Ȃ���
	int poss[60] = { 0 };//�b�����艽�l�������Ȃ���΂����Ȃ���
	int negm[19][2][60] = { 0 };//�����OPD�܂� //sensnum,in/out,m
	int negs[19][2][60] = { 0 };//sensnum,in/out,s

	bool isTracking = false;

	int holidaynum = 9;
	int workdaynum = 21;

	/*------------����--------------*/
	//cout << "----------------------------" << endl;
	ifstream ifs;
	ofstream ofs;
	ifs.open("mapdatas/map.txt");	//�}�b�v�̍L���Ƃ�
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

	/*------------������--------------*/
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

	/*----------�{����-------------*/
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

		while (month == 6 /*&& date == 1*/) {//�ꂩ�����̃��[�v
		//while(date == 1){//�������
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
			ifs.open(filename.c_str());	//�Z���TID�Cyyyy/m/d, h:mm, in, out, in�݌v, out�݌v\n
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
			while (getline(ifs, line)) {//�I�[�v���f�[�^���̃��[�v,������̃��[�v
				vector<string> strvec = split(line, ',');//�f�[�^��s�Q�b�g
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
					else {//�P�����I��
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
			//������̓��͏I�������
			ifs.close();
			//cout << "end_input" << endl;

			/*cout << "test" << endl;
			for (int m = 0; m < 60; m++) {
				cout << negm[10][0][m] << endl;
			}*/

			for (int m = 0; m < 60; m++) {//�ꕪ���̃��[�v
				cout << "posnum:" << posnum << "  minuts:" << m << endl;
				//cout << "pos:" << posm[m] << endl;
				to60(posm[m], poss);//���̃f�[�^��b���ɕϊ�
				//cout << "posend" << endl;
				for (int num = 0; num < 19; num++) {//���̃f�[�^��b���ɕϊ�
					to60(negm[num][0][m], negs[num][0]);
					to60(negm[num][1][m], negs[num][1]);
				}
				for (int s = 0; s < 60; s++) {//��b���̃��[�v
					//cout << "sec:" << s << endl;
					for (int i = 0; i < poss[s]; i++) {//�w���Ώێ҂𐶂�
						//cout << "PosBorn" << endl;
						//scanf_s("%d", &i);
						PosMngBorn();
					}
					for (int num = 0; num < 19; num++) {//�w����Ώێ҂𐶂�
						for (int i = 0; i < negs[num][0][s]; i++) {
							NegMngBorn(num, 0);
						}
						for (int i = 0; i < negs[num][1][s]; i++) {
							NegMngBorn(num, 1);
						}
					}
					RTMngUpdate(PosMngGet(), NegMngGet());//���܂ꂽ�u�Ԃ�n��
					PplMngUpdate();//�n���Ă���i��

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
		}//6���̃��[�v

		//RTMngOutput("result.csv");
		ratio[posnum / 25] = RTMngGetRatio();
		cratio[posnum / 25] = CloudRatio();
		//break;//1�����Ńe�X�g
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