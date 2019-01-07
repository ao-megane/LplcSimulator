#ifndef RT_H
#define RT_H
#include"Camera.h"
#include"People.h"

class RT
{
public:
	int Initialize(int h,int w,int x,int y,int r);
	int UpdatePos(People pos[]);//1s
	int UpdatePostest(People pos[]);
	int UpdateNeg(People neg[]);//1s
	int Reset();
	Field GetART();
	Camera* GetCameraAd(int num);
	//int SetCameras(Camera cam1, Camera cam2);
	int Getposdata();
	int Getnegdata();
	double GetNPDRatio();
	RT();
	~RT();

private:
	int x;//¶ã©ç
	int y;//¶ã©ç
	int r;//ANZXLøÍÍ
	Camera camera[2];//2ÅÅè(in/out)
	Field ART;
	int posdata;
	int negdata;
};

int RTMngInitialize(int h,int w);
int RTMngUpdate(People pos[], People neg[]);//1sÉXVÏÝPeopleªn³êé
int RTMngOutput();//csvÉf«oµ
int RTMngReset();

int testRTInitialize(int h, int w);
int testRTUpdate(People* pos);
int testRTOutput();
int RTMngtestDraw();

#endif // !RT_H


