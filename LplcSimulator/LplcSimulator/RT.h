#ifndef RT_H
#define RT_H
#include"Camera.h"
#include"People.h"

class RT
{
public:
	int Initialize(int h,int w,int x,int y,int r);
	int UpdatePos(People pos[]);//1s��
	int UpdatePostest(People pos[]);
	int UpdateNeg(People neg[]);//1s��
	int Update(People pos[], People neg[]);//1s�� ����݂̂��{���I
	int Reset();
	Field GetART();
	Camera* GetCameraAd(int num);
	//int SetCameras(Camera cam1, Camera cam2);
	int Getposdata();
	int Getnegdata();
	double GetNPDRatio();
	int nonWork();
	int Working();
	RT();
	~RT();

private:
	int x;//���ォ��
	int y;//���ォ��
	int r;//�A�N�Z�X�L���͈�
	Camera camera[2];//2�ŌŒ�(in/out)
	Field ART;
	int posdata;
	int negdata;
	bool isWork;
};

int RTMngInitialize(int h,int w);
int RTMngUpdate(People pos[], People neg[]);//1s���ɍX�V�ς�People���n�����
int RTMngOutput(string filename);//csv�ɓf���o��
int RTMngReset();

int testRTInitialize(int h, int w);
int testRTUpdate(People* pos);
int testRTOutput();
int RTMngtestDraw();

#endif // !RT_H


