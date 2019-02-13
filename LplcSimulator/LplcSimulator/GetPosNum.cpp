#include"GetPosNum.h"

int SetRand() {
	srand((unsigned int)time(NULL));
	return 0;
}

//0<= GetRand() < 100
int GetRand() {
	return rand() % 100;
}

int GetPosNum() {//1ƒx[ƒX‚ð•Ô‚·
	int a = GetRand();
	if (a < 5) {
		cout << "playerbornat:6" << endl;
		return 6;
	}
	else if (a < 5 + 21) {
		cout << "playerbornat:9" << endl;
		return 9;
	}
	else if (a < 5 + 21 + 24) {
		cout << "playerbornat:10" << endl;
		return 10;
	}
	else if (a < 5 + 21 + 24 + 13) {
		cout << "playerbornat:12" << endl;
		return 12;
	}
	else if (a < 5 + 21 + 24 + 13 + 37) {
		cout << "playerbornat:13" << endl;
		return 13;
	}
	else {
		cout << "RAND ERROR!" << endl;
	}
	return -1;
}