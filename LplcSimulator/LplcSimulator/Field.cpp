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

Field::Field()
{
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