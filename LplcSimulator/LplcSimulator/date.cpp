#include"date.h"

int day[2][13] = {
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
};

/*--- year���[�N�ł����1�������łȂ����0��Ԃ� ---*/
int isleap(int year){
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

/*--- �󂯎�������t�̎��̓������߂� ---*/
void tomorrow(int *y, int *m, int *d){
	if (*d != day[isleap(*y)][*m]) // �ŏI���łȂ����*d���C���N�������g
		(*d)++;
	else {
		if (*m != 12)   // 12���ȊO�̍ŏI��
			(*m)++;
		else {      // 12��31��
			(*y)++;
			*m = 1;
		}
		*d = 1;
	}
}

string ttos(int y, int m, int d) {//time���󂯎��C�I�[�v���f�[�^�ɍ��킹��string��Ԃ�
	string result = "";
	result += to_string(y);
	if (m < 10) {//�ꌅ�Ȃ�ttos
		result += "0";
		result += to_string(m);
	}
	else {
		result += to_string(m);
	}
	if (d < 10) {//�ꌅ�Ȃ�
		result += "0";
		result += to_string(d);
	}
	else {
		result += to_string(d);
	}

	return result;
}

string ttos(int time,bool isfilename) {//time���󂯎��C�I�[�v���f�[�^�ɍ��킹��string��Ԃ�
	string result = "";
	if (time < 10) {//�ꌅ�Ȃ�
		result += "0";
		result += to_string(time);
	}
	else {
		result += to_string(time);
	}
	if (isfilename) {
		result += "_00";
	}
	else {
		result += ":00";
	}
	
	return result;
}

//�j�������߂�(�c�F���[�̌���)(http://www.aoharu-b.com/cgi/sk/2008/03/zellerc.html)
int aaa(int y, int m, int d) {
	if (m < 3) {
		y--;
		m += 12;
	}
	return (y + y / 4 - y / 100 + y / 400 + (13 * m + 8) / 5 + d) % 7;
	//�����ΐ��؋��y�̏�(0~6)
}
