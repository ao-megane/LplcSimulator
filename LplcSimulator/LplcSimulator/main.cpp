#include <iostream>
#include <fstream>
#include <time.h>
#include <iomanip>
#include "Camera.h"
#include "date.h"
#include "GetPosNum.h"
#include "Field.h"

int main() {

	string line;
	string start;	//�v���J�n����	//hh:mm�Ƃ����`���Ȃ̂Œ���
	string end;		//�v���I������
	string filename;	//���т��ѕς��t�@�C���l�[���C�g���܂킵�܂���̂ŏ�������Y��Ȃ��悤��
	int year;
	int month;
	int date;
	int i = 0;
	int width = 0;
	int height = 0;

	bool isTracking = false;
	double ratio[30] = { 0 };

	int holidaynum = 9;
	int workdaynum = 21;

	SetRand();

	ifstream ifs;
	ofstream ofs;
	ifs.open("mapdatas/allmap/map.txt");	//�}�b�v�̍L���Ƃ�
	if (!ifs) {
		cout << "�t�@�C���I�[�v���Ɏ��s" << "mapdatas/map.txt" << endl;
	}
	int mapdata[2] = { 0 };
	if (getline(ifs, line)) {
		vector<string> strvec = split(line, ',');
		mapdata[0] = stoi(strvec.at(0));
	}
	if (getline(ifs, line)) {
		vector<string> strvec = split(line, ',');
		mapdata[1] = stoi(strvec.at(0));
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
	width = mapdata[0];
	height = mapdata[1];//�}�b�v�̍L�����i�[

	for (int i = 0; i < 19; i++) {
		positive[i].resize(height);
	}
	for (int i = 0; i < 19; i++) {//�傫���i�[
		in[i].resize(height);
		out[i].resize(height);
		for (int j = 0; j < height; j++) {
			in[i][j].resize(width);
			out[i][j].resize(width);
		}
	}
	for (int i = 0; i < height; i++) {
		map[i].resize(width);
		decoi[i].resize(width);
		for (int num = 0; num < 19; num++) {
			positive[num][i].resize(width);
		}
	}

	//pos�t�@�C���ǂݍ���&�i�[
	for (int i = 0; i < 19; i++) {
		filename = "mapdatas/allmap/pos/";
		filename += to_string(i + 1);
		filename += ".csv";
		cout << filename << endl;
		ifs.open(filename.c_str());
		if (!ifs) {
			cout << "�t�@�C���I�[�v���Ɏ��s" << filename << endl;
			for (int h = 0; h < height; h++) {
				for (int w = 0; w < width; w++) {
					positive[i][h][w] = 0;
				}
			}
			continue;
		}
		else {
			int j = 0, k = 0;
			while (getline(ifs, line)) {
				vector<string> strvec = split(line, ',');
				for (k = 0; k < strvec.size(); k++) {
					if (strvec.at(k) == "") positive[i][j][k] = 0;
					else positive[i][j][k] = stoi(strvec.at(k));
				}
				j++;
			}
		}
		ifs.close();
		//cout << i << endl;
	}

	//�Z���T�L���͈͂ɂ��Ă�for���[�v
	int range = 11;
	for (int t = 0; t < 1; t++) {
		range = 11;
		//�e�Z���T�ɗL���͈͂��i�[(�Z���T�ɂ��Ă�for���[�v)
		for (int i = 0; i < 19; i++) {
			filename = "mapdatas/allmap/";
			filename += to_string(range + 1);
			filename += "/";
			filename += to_string(i + 1);
			filename += "in.csv";

			//cout << filename << endl;
			ifs.open(filename.c_str());
			if (!ifs) {
				cout << "�t�@�C���I�[�v���Ɏ��s" << filename << endl;
			}

			int j = 0, k = 0;
			while (getline(ifs, line)) {
				vector<string> strvec = split(line, ',');
				for (k = 0; k < strvec.size(); k++) {
					if (strvec.at(k) == "") in[i][j][k] = 0;
					else in[i][j][k] = stoi(strvec.at(k));
				}
				j++;
			}
			ifs.close();

			filename = "mapdatas/allmap/";
			filename += to_string(range + 1);
			filename += "/";
			filename += to_string(i + 1);
			filename += "out.csv";
			//cout << filename << endl;
			ifs.open(filename.c_str());
			if (!ifs) {
				cout << "�t�@�C���I�[�v���Ɏ��s" << filename << endl;
			}
			j = 0; k = 0;
			while (getline(ifs, line)) {
				vector<string> strvec = split(line, ',');
				for (k = 0; k < strvec.size(); k++) {
					if (strvec.at(k) == "") out[i][j][k] = 0;
					else out[i][j][k] = stoi(strvec.at(k));
				}
				j++;
			}
			ifs.close();
		}

		//�Z���T������
		for (int i = 0; i < 19; i++) {
			sensor[i].Initialize();
		}

		//�}�b�v������
		for (int i = 0; i < map.size(); ++i) {
			for (int j = 0; j < map[i].size(); ++j) {
				map[i][j] = 0;
			}
		}
		cout << "----------------------------" << endl;

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
		for (int i = 0; i < 19; i++) {
			sensor[i].Initialize();
		}
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
			for (int i = 0; i < map.size(); ++i) {
				for (int j = 0; j < map[i].size(); ++j) {
					map[i][j] = 0;
				}
			}

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
					for (int h = 0; h < height; h++) {
						for (int w = 0; w < width; w++) {
							sensor[i].nAdd(stoi(strvec.at(3)) * in[i][h][w], stoi(strvec.at(4))*out[i][h][w]);
						}
					}

					if (i < 18) {
						i++;
					}
					else {//�P�����I���C�}�b�v�X�V
						  //cout << "���쒆�I�I" << endl;
						for (int id = 0; id < 19; id++) {
							for (int h = 0; h < height; h++) {
								for (int w = 0; w < width; w++) {//map�ɏ�������
									map[h][w] += in[id][h][w] * sensor[id].GetnIn();
									map[h][w] += out[id][h][w] * sensor[id].GetnOut();
									data[id * 2 + 0] += in[id][h][w] * sensor[id].GetnIn();
									data[id * 2 + 1] += out[id][h][w] * sensor[id].GetnOut();
								}
							}
						}
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
		for (int pos = 0; pos <= 200; pos += 10) {
			//int posnum = 1000;	//�����Ŋ�����̂ŁC����50�l���炢
			cout << pos << endl;
			int posnum = workdaynum * pos;
			int num;
			for (int i = 0; i < 30; i++) {//30�{�񂵂�
				for (int t = 0; t < posnum; t++) {//�l��
					num = GetPosNum();//n�l�ڂ̃��[�g����
					for (int id = 0; id < 19; id++) {//�Z���T�S���Ń`�F�b�N
						for (int h = 0; h < height; h++) {
							for (int w = 0; w < width; w++) {
								if (id == 9 || id == 11) {
									sensor[id].pAdd(0, positive[num - 1][h][w] * out[id][h][w]);
									continue;
								}
								if (id == 7 || id == 13) {
									sensor[id].pAdd(positive[num - 1][h][w] * in[id][h][w], 0);
									continue;
								}
								sensor[id].pAdd(positive[num - 1][h][w] * in[id][h][w], positive[num - 1][h][w] * out[id][h][w]);
							}
						}
					}
				}
			}
			for (int id = 0; id < 19; id++) {//���ςɂ���
				sensor[id].pDivision(30.0);
			}

			int negdata = 0;
			int posdata = 0;
			for (int i = 0; i < 19; i++) {
				negdata += (sensor[i].GetSumnIn() + sensor[i].GetSumnOut());
				posdata += (sensor[i].GetSumpIn() + sensor[i].GetSumpOut());
			}

			ratio[pos / 10] = (double)(negdata) / (posdata + negdata);
		}
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