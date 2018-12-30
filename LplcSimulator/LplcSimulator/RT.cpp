#include"RT.h"

RT::RT()
{
}

RT::~RT()
{
}

int RT::Initialize(int h,int w,int x, int y, int r) {
	ART.Initialize(h, w);
	posdata = 0;
	negdata = 0;
	return 0;
}
int RT::UpdatePos(People pos[]) {
	for (int i = 0; i < POS_NUM; i++) {
		if (pos[i].GetisExist()) {//存在して
			if (ART.GetValue(pos[i].GetNowPos()) == 1) {//もしアクセス可能圏にいれば
				for (int j = 0; j < 2; j++) {
					posdata += camera[j].Filming(pos[i]);//撮影！
				}
			}
		}
	}
	return 0;
}
int RT::UpdateNeg(People neg[]) {
	for (int i = 0; i < NEG_NUM; i++) {
		if (neg[i].GetisExist()) {//存在して
			if (ART.GetValue(neg[i].GetNowPos()) == 1) {//もしアクセス可能圏にいれば
				for (int j = 0; j < 2; j++) {
					negdata += camera[j].Filming(neg[i]);//撮影！
				}
			}
		}
	}
	return 0;
}

int RT::SetCameras(Camera cam1, Camera cam2) {
	camera[0] = cam1;
	camera[1] = cam2;
	return 0;
}

Field RT::GetART() {
	return ART;
}
Camera* RT::GetCameraAd(int num) {
	if (num == 0 || num == 1) {
		return &camera[num];
	}
	else {
		cout << "GETCAMERAADERROR!!" << endl;
	}
}

RT sensor[19];

int RTMngInitialize() {
	for (int i = 0; i < 19; i++) {//入力して整理してあるmotherからカメラに移す感じ
		sensor[i].GetCameraAd(0)->Initialize(MomMngGetCamera(i, 0));
		sensor[i].GetCameraAd(1)->Initialize(MomMngGetCamera(i, 1));
	}
	return 0;
}