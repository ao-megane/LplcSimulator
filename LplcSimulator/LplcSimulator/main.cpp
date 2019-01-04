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
	int year;
	int month;
	int date;
	int i = 0;
	int width = 0;//�}�b�v�̍L��(�SField�N���X�ŋ���)
	int height = 0;//�}�b�v�̍L��(�SField�N���X�ŋ���)

	int test[60] = { 0 };

	bool isTracking = false;
	double ratio[30] = { 0 };

	int holidaynum = 9;
	int workdaynum = 21;

	to60Initialize();

	to60(63,test);
	/*for (int i = 0; i < 30; i++) {
		cout << test[i] << ",";
		test[i] = 0;
	}
	cout << endl;*/

	/*------------����--------------*/
	//cout << "----------------------------" << endl;
	ifstream ifs;
	ofstream ofs;
	ifs.open("mapdatas/map.txt");	//�}�b�v�̍L���Ƃ�
	if (!ifs) {
		cout << "�t�@�C���I�[�v���Ɏ��s" << "mapdatas/map.txt" << endl;
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

	/*------------������--------------*/
	SetRand();
	/*---------test--------------*/
	testMomInitialize(height,width);
	testPplMngInitialize(height, width);
	testRTInitialize(height, width);

	testPosMngBorn();

	for (int i = 0; i < 30; i++) {
		testRTUpdate(testPosGet());
		testPosMngUpdate();
	}





	/*-----------test-------------*/
	//MomMngInitialize(height, width);
	//PplMngInitialize(height, width);

	//pos�t�@�C���ǂݍ���&�i�[
	//for (int i = 0; i < 19; i++) {
	//	filename = "mapdatas/allmap/pos/";
	//	filename += to_string(i + 1);
	//	filename += ".csv";
	//	cout << filename << endl;
	//	ifs.open(filename.c_str());
	//	if (!ifs) {
	//		cout << "�t�@�C���I�[�v���Ɏ��s" << filename << endl;
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

	//�Z���T�L���͈͂ɂ��Ă�for���[�v
	//cout << "----------------------------" << endl;
	int range = 11;
	for (int t = 0; t < 1; t++) {
		range = 11;
		

		//�Z���T������
		/*for (int i = 0; i < 19; i++) {
			sensor[i].Initialize();
		}*/

		//�}�b�v������
		/*for (int i = 0; i < map.size(); ++i) {
			for (int j = 0; j < map[i].size(); ++j) {
				map[i][j] = 0;
			}
		}*/
		//cout << "----------------------------" << endl;

		//���t������
		year = 2018;
		month = 6;
		date = 1;
		int data[19 * 2] = { 0 };
		//30������time�����܂Ƃ߂ď���
		//for (int time = 5; time < 24; time++) {
		year = 2018;
		month = 6;
		date = 1;
		//�Z���T������
		/*for (int i = 0; i < 19; i++) {
			sensor[i].Initialize();
		}*/
		for (int count = 0; count < 30; count++) {//���t
			if (aaa(year, month, date) == 0 || aaa(year, month, date) == 6) {
				cout << "�x��(�J�E���g���Ȃ�)" << ttos(year, month, date) << endl;
				tomorrow(&year, &month, &date);
				continue;
			}
			else {
				//cout << "����(�J�E���g���Ȃ�)" << ttos(year, month, date) << endl;
				//tomorrow(&year, &month, &date);
				//continue;
			}
			//cout << time << ":";
			cout << date << ":";
			//cout << count << ":" << endl;
			//�}�b�v������
			/*for (int i = 0; i < map.size(); ++i) {
				for (int j = 0; j < map[i].size(); ++j) {
					map[i][j] = 0;
				}
			}*/

			filename = "opendatas/";
			filename += ttos(year, month, date);
			filename += ".csv";
			ifs.open(filename);	//�Z���TID�Cyyyy/m/d, h:mm, in, out, in�݌v, out�݌v\n
			if (!ifs) {
				cout << "�t�@�C���I�[�v���Ɏ��s" << filename << endl;
				tomorrow(&year, &month, &date);
				continue;
			}
			else {
				//cout << "�t�@�C���I�[�v���ɐ���" << filename << endl;
				//count++;
			}
			i = 0;
			while (getline(ifs, line)) {//�I�[�v���f�[�^���̃��[�v
				vector<string> strvec = split(line, ',');//�f�[�^��s�Q�b�g
														 //if (strvec.at(2) == ttos(start,0)) {//�f�[�^�̎��ԕ]��
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
					//cout << "�v����" ;

					//cout << strvec.at(2) << endl;
					//�Z���T�X�V
					/*for (int h = 0; h < height; h++) {
						for (int w = 0; w < width; w++) {
							sensor[i].nAdd(stoi(strvec.at(3)) * in[i][h][w], stoi(strvec.at(4))*out[i][h][w]);
						}
					}*/

					if (i < 18) {
						i++;
					}
					else {//�P�����I���C�}�b�v�X�V
						//cout << "���쒆�I�I" << endl;
						//for (int id = 0; id < 19; id++) {
						//	for (int h = 0; h < height; h++) {
						//		for (int w = 0; w < width; w++) {//map�ɏ�������
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
		}//30���I���

		 //�Ώێ҂ɂ���
		//for (int pos = 0; pos <= 200; pos += 10) {
		//	//int posnum = 1000;	//�����Ŋ�����̂ŁC����50�l���炢
		//	cout << pos << endl;
		//	int posnum = workdaynum * pos;
		//	int num;
		//	for (int i = 0; i < 30; i++) {//30�{�񂵂�
		//		for (int t = 0; t < posnum; t++) {//�l��
		//			num = GetPosNum();//n�l�ڂ̃��[�g����
		//			for (int id = 0; id < 19; id++) {//�Z���T�S���Ń`�F�b�N
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
		//	for (int id = 0; id < 19; id++) {//���ςɂ���
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
	}//range�I���

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