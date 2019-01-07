#include "to60.h"


//1,2,3,4,5,6,10,12,15,20,30,60
const int nums[12] = { 1,2,3,4,5,6,10,12,15,20,30,60 };
int val[12][60];

int to60Initialize() {
	
	int rate = 0;
	for (int i = 0; i < 12; i++) {
		rate = 60 / nums[i];
		for (int j = 0; j < 60; j++) {
			if (rate == 0) {
				val[i][j] = 1;
				continue;
			}
			if (j % rate == 0) {
				val[i][j] = 1;
			}
			else {
				val[i][j] = 0;
			}
		}
	}
	
	/*cout << "to60_test" << endl;
	for (int i = 0; i < 12; i++) {
		cout << nums[i] << ":" ;
		for (int j = 0; j < 60; j++) {
			cout << val[i][j] << ",";
		}
		cout << endl;
	}*/

	return 0;
}

int to60(int num,int* result) {
	//int result[60] = { 0 };
	for (int i = 0; i < 60; i++) {
		result[i] = 0;
	}
	int decoi = num;
	while (num) {
		for (int i = 11; i >= 0; i--) {//‘å‚«‚¢•û‚©‚ç”äŠr
			if (num >= nums[i]) {//‘å‚«‚¢”š‚Ì“ü‚é—]’n‚ª‚ ‚ê‚Î
				num -= nums[i];
				for (int j = 0; j < 60; j++) {
					result[j] += val[i][j];
				}
				break;
			}
		}
	}
	/*cout << "to60:" << decoi << endl;
	for (int i = 0; i < 60; i++) {
		cout << result[i] << ",";
	}
	cout << endl;*/
	//return result;
	return 0;
}