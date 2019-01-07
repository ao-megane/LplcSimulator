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
	Dot center;
	center.Set(x, y);
	ART.SetART(center, r);

	return 0;
}
int RT::UpdatePos(People pos[]) {
	double result = 0;
	int a;
	for (int i = 0; i < POS_NUM; i++) {
		if (pos[i].GetisExist()) {//存在して
			//cout << "POS_EXIST!" << endl;
			if (ART.GetValue(pos[i].GetNowPos().reverseDot()) == 1) {//もしアクセス可能圏にいれば
				cout << "POS_ART_YES" << endl;
				scanf_s("%d", &a);
				for (int j = 0; j < 2; j++) {
					if(camera[j].GetDir() != DEFAULT){//撮影方向があれば(普通全部ある)
						//result += camera[j].Filming(pos[i]);//撮影！
						posdata += camera[j].Filming(pos[i]);//撮影！
					}
				}
			}
			else {
				//cout << "POS_ART_NON" << endl;
				//cout << pos[i].GetNowPos().reverseDot().GetxtoW() << "," << pos[i].GetNowPos().reverseDot().GetytoW() << endl;
				//scanf_s("%d", &a);
			}
		}
	}
	//return result;
	if (posdata > 0) scanf_s("%d", &a);
	return posdata;
}
int RT::UpdatePostest(People pos[]) {
	double result = 0;
	for (int i = 0; i < 1; i++) {
		if (pos[i].GetisExist()) {//存在して
			if (ART.GetValue(pos[i].GetNowPos()) == 1) {//もしアクセス可能圏にいれば
				for (int j = 0; j < 2; j++) {
					if (camera[j].GetDir() != DEFAULT) {//撮影方向があれば(普通全部ある)
						//result += camera[j].Filming(pos[i]);//撮影！
						posdata += camera[j].Filming(pos[i]);//撮影！
					}
				}
			}
		}
	}
	//return result;
	return posdata;
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
int RT::Reset() {
	posdata = 0;
	negdata = 0;
	return 0;
}

//int RT::SetCameras(Camera cam1, Camera cam2) {
//	camera[0] = cam1;
//	camera[1] = cam2;
//	return 0;
//}

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
int RT::Getposdata() {
	return posdata;
}
int RT::Getnegdata() {
	return negdata;
}
double RT::GetNPDRatio() {
	if (posdata + negdata) {
		return (double)negdata / (posdata + negdata);
	}
	else {
		return -1;
	}
}

RT rt[19];
int RTMngInitialize(int h,int w) {
	for (int i = 0; i < 19; i++) {//入力して整理してあるmotherからカメラに移す感じ
		/*rt[i].Initialize(h, w, RTPOS[2 * i], RTPOS[2 * i + 1], RTRANGE);*/
		rt[i].Initialize(h, w, RTPOS[2 * i+1], RTPOS[2 * i + 0], RTRANGE);
		cout << i + 1 << "in :";
		rt[i].GetCameraAd(0)->Initialize(MomMngGetCamera(i, 0));
		cout << i + 1 << "out:";
		rt[i].GetCameraAd(1)->Initialize(MomMngGetCamera(i, 1));
	}
	Field test;
	test.Initialize(h, w);
	for (int i = 0; i < 19; i++) {
		test += rt[i].GetART();
	}
	test.Output("test.csv");
	return 0;
}
int RTMngUpdate(People pos[], People neg[]) {
	int a;
	for (int i = 0; i < 19; i++) {
		rt[i].UpdatePos(pos);
		//cout << i << " updata : " << rt[i].UpdatePos(pos) << endl;
		cout << i << " posdata : " << rt[i].Getposdata() << endl;

		if (i == 10) {
			//rt[i].GetCameraAd(0)->testDraw();
			//pos[0].testDraw();
			//scanf_s("%d", &a);
			/*cout << pos[0].GetNowPos().reverseDot().GetxtoW() << "," << pos[0].GetNowPos().reverseDot().GetytoW() << endl <<
				rt[i].GetART().GetValue(pos[0].GetNowPos()) << endl;*/
			//rt[i].GetART().fulltestDraw();
			//rt[i].GetART().eachtestDraw();
		}
		//rt[i].UpdateNeg(neg);
		//cout << "negdata! : " << rt[i].UpdateNeg(neg) << endl;
	}
	//scanf_s("%d", &a);
	return 0;
}
int RTMngOutput() {
	//csvに吐く
	return 0;
}
int RTMngReset() {
	for (int i = 0; i < 19; i++) {
		rt[i].Reset();
	}
	return 0;
}

RT test;
int testRTInitialize(int h,int w) {
	//test.Initialize(h, w, TESTRTPOS[0], TESTRTPOS[1], TESTRTRANGE);
	test.Initialize(h, w, TESTRTPOS[1], TESTRTPOS[0], TESTRTRANGE);
	test.GetCameraAd(0)->Initialize(testMomGetCamera());
	cout << "ART_TEST" << endl;
	test.GetART().testDraw();
	cout << "ART_TEST_END" << endl;
	cout << "camera_test" << endl;
	test.GetCameraAd(0)->testDraw();
	cout << "camera_test_end" << endl << endl;
	return 0;
}
int testRTUpdate(People* pos) {
	//cout << "filming:" << test.UpdatePos(pos) << endl << endl;
	cout << "filming:" << test.UpdatePostest(pos) << endl << endl;
	return 0;
}
int testRTOutput() {
	return 0;
}
int RTMngtestDraw() {
	for (int i = 0; i < 19; i++) {
		cout << setw(2) << i + 1 << ",in:" << setw(5) << rt[i].Getposdata() << " out:" << setw(5) << rt[i].Getnegdata() << " NPDRatio:" << setw(3) << rt[i].GetNPDRatio() << endl;
	}
	return 0;
}