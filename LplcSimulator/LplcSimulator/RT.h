#ifndef RT_H
#define RT_H
#include"Camera.h"
#include"People.h"

class RT
{
public:
	int Initialize(int h,int w,int x,int y,int r);
	int UpdatePos(People pos[]);//1s��
	int UpdateNeg(People neg[]);//1s��
	Field GetART();
	Camera* GetCameraAd(int num);
	int SetCameras(Camera cam1, Camera cam2);
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
};

int RTMngInitialize();
int RTMngUpdate(People pos[], People neg[]);//1s���ɍX�V�ς�People���n�����
int RTMngOutput();//csv�ɓf���o��

#endif // !RT_H


