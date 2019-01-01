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
	for (int i = 0; i < POS_NUM; i++) {
		if (pos[i].GetisExist()) {//‘¶Ý‚µ‚Ä
			if (ART.GetValue(pos[i].GetNowPos()) == 1) {//‚à‚µƒAƒNƒZƒX‰Â”\Œ—‚É‚¢‚ê‚Î
				for (int j = 0; j < 2; j++) {
					result += camera[j].Filming(pos[i]);//ŽB‰eI
					posdata += camera[j].Filming(pos[i]);//ŽB‰eI
				}
			}
		}
	}
	return result;
}
int RT::UpdateNeg(People neg[]) {
	for (int i = 0; i < NEG_NUM; i++) {
		if (neg[i].GetisExist()) {//‘¶Ý‚µ‚Ä
			if (ART.GetValue(neg[i].GetNowPos()) == 1) {//‚à‚µƒAƒNƒZƒX‰Â”\Œ—‚É‚¢‚ê‚Î
				for (int j = 0; j < 2; j++) {
					negdata += camera[j].Filming(neg[i]);//ŽB‰eI
				}
			}
		}
	}
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

RT rt[19];
int RTMngInitialize(int h,int w) {
	for (int i = 0; i < 19; i++) {//“ü—Í‚µ‚Ä®—‚µ‚Ä‚ ‚émother‚©‚çƒJƒƒ‰‚ÉˆÚ‚·Š´‚¶
		rt[i].Initialize(h, w, RTPOS[2 * i], RTPOS[2 * i + 1], RTRANGE);
		rt[i].GetCameraAd(0)->Initialize(MomMngGetCamera(i, 0));
		rt[i].GetCameraAd(1)->Initialize(MomMngGetCamera(i, 1));
	}
	return 0;
}
int RTMngUpdate(People pos[], People neg[]) {
	for (int i = 0; i < 19; i++) {
		rt[i].UpdatePos(pos);
		rt[i].UpdateNeg(neg);
	}
	return 0;
}
int RTMngOutput() {
	//csv‚É“f‚­
	return 0;
}

RT test;
int testRTInitialize(int h,int w) {
	test.Initialize(h, w, TESTRTPOS[0], TESTRTPOS[1], TESTRTRANGE);
	test.GetCameraAd(0)->Initialize(testMomGetCamera());
	cout << "ART_TEST" << endl;
	test.GetART().testDraw();
	cout << "ART_TEST_END" << endl;
	cout << "camera_test" << endl;
	test.GetCameraAd(0)->testDraw();
	cout << "camera_test_end" << endl;
	return 0;
}
int testRTUpdate(People* pos) {
	cout << "filming:" << test.UpdatePos(pos) << endl << endl;
	return 0;
}
int testRTOutput() {
	return 0;
}