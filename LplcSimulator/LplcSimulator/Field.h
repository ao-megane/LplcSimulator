#pragma once
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
	int Initialize(int h,int w);

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
};

Field::Field()
{
}

Field::~Field()
{
}