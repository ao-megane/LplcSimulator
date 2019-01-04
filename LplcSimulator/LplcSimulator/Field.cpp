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
Dot Field::Set(string filename) {
	Dot result;//ルート読み込みついでに初期位置も返してあげちゃう，変な書き方してごめんね
	string line;
	ifstream ifs;
	ofstream ofs;
	//cout << filename << endl;
	ifs.open(filename.c_str());
	//cout << "aaaa" << endl;
	if (!ifs) {
		/*cout << "ファイルオープンに失敗" << filename << endl;*/
		cout << "filed:" << filename << endl;
	}
	else {
		/*cout << "ファイルオープンに成功" << filename << endl;*/
		cout << "succes:" << filename << endl;
	}
	int j = 0, k = 0;
	while (getline(ifs, line)) {
		vector<string> strvec = split(line, ',');
		for (k = 0; k < strvec.size(); k++) {
			if (strvec.at(k) == "") {
				SetValue(j, k, 0);
				continue;
			}
			if (stoi(strvec.at(k)) == 2) {//スタート地点
				result.Set(j, k);
				//sensor[i][0].GetBornPos().Set(j, k);
			}
			SetValue(j, k, 1);
		}
		j++;
	}
	ifs.close();
	result.toO();
	return result;
}

int Field::SetValue(int x, int y, double value) {
	field[x][y] = value;
	return 0;
}
int Field::SetValue(Dot pos, double value) {
	field[pos.GetxtoO()][pos.GetytoO()] = value;
	return 0;
}
int Field::SetAllZero() {
	for (int i = 0; i < field.size(); i++) {//縦，ｈ
		for (int j = 0; j < field[i].size(); j++) {//横，ｗ
			field[i][j] = 0;
		}
	}
	return 0;
}
int Field::SetART(Dot center, int r) {
	for (int i = 0; i < field.size(); i++) {//縦，ｈ
		for (int j = 0; j < field[i].size(); j++) {//横，ｗ
			if (center.GetxtoO() - r <= j && j <= center.GetxtoO() + r && center.GetytoO() - r <= i && i <= center.GetytoO() + r) {
				field[i][j] = 1;
			}
			else {
				field[i][j] = 0;
			}
			/*if (i == center.Getx() && j == center.Gety()) {
				field[i][j] = 1;
			}
			else {
				field[i][j] = 0;
			}*/
		}
	}
	return 0;
}
int Field::SetART(int x,int y, int r) {
	for (int i = 0; i < field.size(); i++) {//縦，ｈ
		for (int j = 0; j < field[i].size(); j++) {//横，ｗ
			if (x - r <= j && j <= x + r && y - r <= i && i <= y + r) {
				field[i][j] = 1;
			}
			else {
				field[i][j] = 0;
			}
		}
	}
	return 0;
}

double Field::GetValue(Dot a) {
	if (a.GetxtoO() < 0 || a.GetytoO() < 0 || a.GetytoO() > field.size() || a.GetxtoO() > field[0].size()) {//場外は-1
		return -1;
	}
	return field[a.GetxtoO()][a.GetytoO()];
}
double Field::GetValue(int x, int y) {//
	cout << "intでのGetValueは注意！座標系めんどい！" << endl;
	if (x < 0 || y < 0 || x > field.size() || y > field[0].size()) {//場外は-1
		return -1;
	}
	return field[x][y];
}


Dot Field::GetStart() {
	Dot result;
	for (int i = 0; i < field.size(); i++) {
		for (int j = 0; j < field[i].size(); j++) {
			if (field[i][j] == 2) {
				result.Set(i, j);
				cout << i << ":" << j;
				return result;
			}
		}
	}
	cout << "GETSTARTERROR!!" << endl;
}
int Field::testDraw() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << field[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
}