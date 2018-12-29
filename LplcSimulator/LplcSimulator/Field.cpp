#include"Field.h"

vector<string> split(string& input, char delimiter) {//delimiterでinputを分割し，vector<string>にまとめて返す
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
double Field::GetValue(int x, int y) {//左上から右下へ数が増える(数学とは上下逆)
	if (x < 0 || y < 0 || x > field.size() || y > field[0].size()) {//場外は-1
		return -1;
	}
	return field[x][y];
}