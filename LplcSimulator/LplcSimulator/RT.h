#ifndef RT_H
#define RT_H
#include"Camera.h"
#include"People.h"

class RT
{
public:
	int Initialize(int h,int w,int x,int y,int r);
	int UpdatePos(People pos[]);//1s毎
	int UpdatePostest(People pos[]);
	int UpdateNeg(People neg[]);//1s毎
	int Update(People pos[], People neg[]);//1s毎 これのみが本命！
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
	int x;//左上から
	int y;//左上から
	int r;//アクセス有効範囲
	Camera camera[2];//2で固定(in/out)
	Field ART;
	int posdata;
	int negdata;
	bool isWork;
};

int RTMngInitialize(int h,int w);
int RTMngUpdate(People pos[], People neg[]);//1s毎に更新済みPeopleが渡される
int RTMngOutput(string filename);//csvに吐き出し
int RTMngReset();

int testRTInitialize(int h, int w);
int testRTUpdate(People* pos);
int testRTOutput();
int RTMngtestDraw();

#endif // !RT_H


