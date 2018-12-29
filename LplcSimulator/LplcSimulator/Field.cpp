#include"Field.h"

vector<string> split(string& input, char delimiter) {//delimiter��input�𕪊����Cvector<string>�ɂ܂Ƃ߂ĕԂ�
	istringstream stream(input);
	string field;
	vector<string> result;
	while (getline(stream, field, delimiter)) {
		result.push_back(field);
	}
	return result;
}

Field::Field(){
}

Field::~Field()
{
}

vector<vector<double>> Field::GetField() {
	return field;
}

int Field::Initialize(int h,int w) {
	field.resize(h);
	for (int i = 0; i < h; i++) {
		field[i].resize(w);
	}
	return 0;
}

int Field::SetValue(int x, int y, double value) {
	field[x][y] = value;
	return 0;
}

double Field::GetValue(Dot a) {
	return field[a.Getx()][a.Gety()];
}
double Field::GetValue(int x, int y) {//���ォ��E���֐���������(���w�Ƃ͏㉺�t)
	if (x < 0 || y < 0 || x > field.size() || y > field[0].size()) {//��O��-1
		return -1;
	}
	return field[x][y];
}