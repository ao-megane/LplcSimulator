#ifndef FIELD_H
#define FIELD_H
#include <vector>
#include <iterator> // 追加
#include <sstream>

using namespace std;

vector<string> split(string& input, char delimiter); //delimiterでinputを分割し，vector<string>にまとめて返す

class Field
{
public:
	Field();
	~Field();
	vector<vector<double>> GetField();
	int Initialize(int h, int w);

private:
	vector<vector<double>> field;
	double operator * (Field afield) {
		double num;
		for (int i = 0; i < field.size(); ++i) {
			for (int j = 0; j < field[i].size(); ++j) {
				num += afield.GetField()[i][j] * field[i][j];
			}
		}
		return num;
	}
	bool operator & (Field afield) {
		double num;
		for (int i = 0; i < field.size(); ++i) {
			for (int j = 0; j < field[i].size(); ++j) {
				if (afield.GetField()[i][j] * field[i][j])
					return true;
			}
		}
		return false;
	}
};

#endif // !FIELD_H


