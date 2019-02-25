#ifndef VALUE_H
#define VALUE_H

const int POS_NUM = 200;
const int NEG_NUM = 400;

const int RTPOS[19 * 2] = {//左上原点に右，下の順
	197 - 1,21 - 1,
	176 - 1,32 - 1,
	171 - 1,11 - 1,
	148 - 1,32 - 1,
	143 - 1,11 - 1,
	129 - 1,14 - 1,
	129 - 1,14 - 1,
	129 - 1,14 - 1,
	114 - 1,10 - 1,
	113 - 1,31 - 1,
	122 - 1,23 - 1,//11
	83 - 1,31 - 1,
	83 - 1,11 - 1,
	79 - 1,17 - 1,
	57 - 1,29 - 1,
	58 - 1,11 - 1,
	37 - 1,10 - 1,
	25 - 1,18 - 1,
	10 - 1,21 - 1
};
const int RTRANGE = 10;//マス

const int TESTRTPOS[2] = {//左上原点に右，下の順
	3,2
};
const int TESTRTRANGE = 2;

#endif // !VALUE_H

