#ifndef DATE_H
#define DATE_H

#include <stdio.h>
#include <string>

using namespace std;

//http://zhi-ma.hatenablog.com/entry/2013/10/11/204331

int isleap(int year);//year���[�N�ł����1�������łȂ����0��Ԃ�

void tomorrow(int *y, int *m, int *d);//�󂯎�������t�̎��̓������߂�

string ttos(int y, int m, int d);//time���󂯎��C�I�[�v���f�[�^�ɍ��킹��string��Ԃ�

string ttos(int time,bool isfilename);//�������󂯎��C�I�[�v���f�[�^�ɍ��킹��string��Ԃ�

int aaa(int y, int m, int d);

#endif // !DATE_H




