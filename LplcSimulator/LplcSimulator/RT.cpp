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
	cout << "UpdatePos is in Update" << endl;
	double result = 0;
	int a;
	for (int i = 0; i < POS_NUM; i++) {
		if (pos[i].GetisExist()) {//‘¶Ý‚µ‚Ä
			if (ART.GetValue(pos[i].GetNowPos()) == 1) {//‚à‚µƒAƒNƒZƒX‰Â”\Œ—‚É‚¢‚ê‚Î
				for (int j = 0; j < 2; j++) {
					if(camera[j].GetDir() != DEFAULT){//ŽB‰e•ûŒü‚ª‚ ‚ê‚Î(•’Ê‘S•”‚ ‚é)
						posdata += camera[j].Filming(pos[i]);//ŽB‰eI
					}
				}
			}
		}
	}
	return posdata;
}
int RT::Update(People pos[], People neg[]) {
	for (int i = 0; i < POS_NUM; i++) {
		if (pos[i].GetisExist()) {//‘¶Ý‚µ‚Ä
			if (ART.GetValue(pos[i].GetNowPos()) == 1) {//‚à‚µƒAƒNƒZƒX‰Â”\Œ—‚É‚¢‚ê‚Î“®ì‚·‚é
				for (int j = 0; j < 2; j++) {
					if (camera[j].GetDir() != DEFAULT) {//ŽB‰e•ûŒü‚ª‚ ‚ê‚Î(•’Ê‘S•”‚ ‚é)
						posdata += camera[j].Filming(pos[i]);//ŽB‰eI
						negdata += camera[j].FilmingNeg(neg);//ˆê‚ÉNPD‚àŽûW‚µ‚¿‚á‚¤I
					}
				}
			}
		}
	}
	return 0;
}
int RT::UpdatePostest(People pos[]) {
	double result = 0;
	for (int i = 0; i < 1; i++) {
		if (pos[i].GetisExist()) {//‘¶Ý‚µ‚Ä
			if (ART.GetValue(pos[i].GetNowPos()) == 1) {//‚à‚µƒAƒNƒZƒX‰Â”\Œ—‚É‚¢‚ê‚Î
				//cout << "POS_ART_YES" << endl;
				for (int j = 0; j < 2; j++) {
					if (camera[j].GetDir() != DEFAULT) {//ŽB‰e•ûŒü‚ª‚ ‚ê‚Î(•’Ê‘S•”‚ ‚é)
						//result += camera[j].Filming(pos[i]);//ŽB‰eI
						posdata += camera[j].Filming(pos[i]);//ŽB‰eI
					}
				}
			}
		}
	}
	//return result;
	return posdata;
}

int RT::UpdateNeg(People neg[]) {
	cout << "UpdateNeg ‚Í•s‰Â”\‚È‚Í‚¸I" << endl;
	int a;
	scanf_s("%d", &a);
	//Pos‚Æ˜A“®‚·‚é‚½‚ßˆá‚¤
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
	for (int i = 0; i < 19; i++) {//“ü—Í‚µ‚Ä®—‚µ‚Ä‚ ‚émother‚©‚çƒJƒƒ‰‚ÉˆÚ‚·Š´‚¶
		//rt[i].Initialize(h, w, RTPOS[2 * i + 0], RTPOS[2 * i + 1], RTRANGE);
		rt[i].Initialize(h, w, RTPOS[2 * i + 1], RTPOS[2 * i + 0], RTRANGE);
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
		//rt[i].UpdatePos(pos);
		rt[i].Update(pos, neg);
		//if (i == 10) {
		//	cout << i+1 << "_posdata : " << rt[i].Getposdata() << endl;
		//	//rt[i].GetCameraAd(0)->testDraw();
		//	rt[i].GetCameraAd(1)->testDraw();
		//	pos[0].testDraw();
		//	//rt[i].GetART().Output("11ART.csv");
		//	//cout << "ART : " << rt[i].GetART().GetValue(pos[0].GetNowPos()) << endl;
		//	//scanf_s("%d", &a);
		//}
	}
	return 0;
}
int RTMngOutput(string filename) {
	int possum = 0, negsum = 0;
	ofstream ofs;
	ofs.open(filename.c_str(), ios::trunc);
	if (!ofs) {
		cout << "failed:" << filename << endl;
	}
	else {
		cout << "succes:" << filename << endl;
	}
	ofs << "ƒZƒ“ƒT”Ô†,pos,neg,pos+neg" << endl;
	for (int i = 0; i < 19; i++) {
		possum += rt[i].Getposdata();
		negsum += rt[i].Getnegdata();
		ofs << i + 1 << "," << rt[i].Getposdata() << "," << rt[i].Getnegdata() << "," << rt[i].Getposdata() + rt[i].Getnegdata() << endl;
	}
	ofs << "‘˜a," << possum << "," << negsum << "," << "," << setprecision(5) << (double)negsum / (possum + negsum) << endl;
	ofs << "‘˜a(ˆê“ú“–‚½‚è)," << possum / 21 << "," << negsum / 21 << "," << "," << setprecision(5) << (double)negsum / (possum + negsum) << endl;
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
		
		cout << setw(2) << i + 1 << ",pos:" << setw(5) << rt[i].Getposdata() << " neg:" << setw(5) << rt[i].Getnegdata() << " NPDRatio:" << setw(3) << rt[i].GetNPDRatio() << endl;
	}
	
	return 0;
}