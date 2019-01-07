#ifndef FIELD_H
#define FIELD_H
#include "Dot.h"
#include <vector>
#include <iterator>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

vector<string> split(string& input, char delimiter); //delimiter‚Åinput‚ğ•ªŠ„‚µCvector<string>‚É‚Ü‚Æ‚ß‚Ä•Ô‚·

class Field
{
public:
	Field();
	~Field();
	vector<vector<double>> GetField();
	vector<vector<double>>* GetFieldAd();
	int Initialize(int h, int w);
	Dot Set(string filename);
	/*void operator = (Field a) {
		if (field.size() != a.GetField().size()) {
			field.resize(a.GetField().size());
		}
		for (int i = 0; i < field.size(); i++) {
			if(field[i].size() != a.GetField()[i].size())
				field[i].resize(a.GetField()[i].size());
		}
		for (int i = 0; i < field.size(); i++) {
			for (int j = 0; j < field[i].size(); j++) {
				field[i][j] = a.GetField()[i][j];
			}
		}
	}*/
	void operator = (Field* a) {
		if (field.size() != a->GetFieldAd()->size()) {
			field.resize(a->GetFieldAd()->size());
		}
		for (int i = 0; i < field.size(); i++) {
			if (field[i].size() != a->GetFieldAd()->at(i).size())
				field[i].resize(a->GetFieldAd()->at(i).size());
		}
		for (int i = 0; i < field.size(); i++) {
			for (int j = 0; j < field[i].size(); j++) {
				field[i][j] = a->GetFieldAd()->at(i)[j];
			}
		}
	}
	double operator * (Field* afield) {
		double num = 0;
		for (int i = 0; i < field.size(); ++i) {
			for (int j = 0; j < field[i].size(); ++j) {
				num += afield->GetFieldAd()->at(i)[j] * field[i][j];
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
	void operator += (Field a) {
		for (int i = 0; i < field.size(); ++i) {
			for (int j = 0; j < field[i].size(); ++j) {
				field[i][j] += a.GetField()[i][j];
			}
		}
	}
	int SetValue(int x, int y, double value);
	int SetValue(Dot pos, double value);
	int SetAllZero();
	int SetART(Dot center, int r);
	int SetART(int x,int y, int r);
	double GetValue(Dot a);
	double GetValue(int x, int y);
	Dot GetStart();
	int Output(string filename);
	int testDraw();
	int fulltestDraw();
	int eachtestDraw();

private:
	vector<vector<double>> field;
};

#endif // !FIELD_H


