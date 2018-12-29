#ifndef FIELD_H
#define FIELD_H
#include "Dot.h"
#include <vector>
#include <iterator> // ’Ç‰Á
#include <sstream>

using namespace std;

vector<string> split(string& input, char delimiter); //delimiter‚Åinput‚ğ•ªŠ„‚µCvector<string>‚É‚Ü‚Æ‚ß‚Ä•Ô‚·

class Field
{
public:
	Field();
	~Field();
	vector<vector<double>> GetField();
	int Initialize(int h, int w);
	void operator = (Field a) {
		field.resize(a.GetField().size());
		for (int i = 0; i < field.size(); i++) {
			field[i].resize(a.GetField()[i].size());
		}
		for (int i = 0; i < field.size(); ++i) {
			for (int j = 0; j < field[i].size(); ++j) {
				field[i][j] = a.GetField()[i][j];
			}
		}
	}
	double GetValue(Dot a);
	double GetValue(int x, int y);

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


