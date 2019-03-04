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
		if (pos[i].GetisExist()) {//���݂���
			if (ART.GetValue(pos[i].GetNowPos()) == 1) {//�����A�N�Z�X�\���ɂ����
				for (int j = 0; j < 2; j++) {
					if(camera[j].GetDir() != DEFAULT){//�B�e�����������(���ʑS������)
						posdata += camera[j].Filming(pos[i]);//�B�e�I
					}
				}
			}
		}
	}
	return posdata;
}

int cloudPos;
int cloudNeg;
int RT::Update(People pos[], People neg[]) {//���[�^�[���Ƃ�
	//for (int i = 0; i < POS_NUM; i++) {
	//	if (pos[i].GetisExist()) {//���݂���
	//		if (ART.GetValue(pos[i].GetNowPos()) == 1) {//�����A�N�Z�X�\���ɂ���Γ��삷��
	//			for (int j = 0; j < 2; j++) {
	//				if (camera[j].GetDir() != DEFAULT) {//�B�e�����������(���ʑS������)
	//					posdata += camera[j].Filming(pos[i]);//�B�e�I
	//					negdata += camera[j].FilmingNeg(neg);//�ꏏ��NPD�����W�����Ⴄ�I
	//				}
	//			}
	//		}
	//	}
	//}
	if (isWork) {
		//cout << "WORKING!" << endl;
		for (int i = 0; i < POS_NUM; i++) {
			if (pos[i].GetisExist()) {
				for (int j = 0; j < 2; j++) {
					if (camera[j].GetDir() != DEFAULT) {
						posdata += camera[j].Filming(pos[i]);
					}
				}
			}
		}
		for (int i = 0; i < NEG_NUM; i++) {
			if (neg[i].GetisExist()) {
				for (int j = 0; j < 2; j++) {
					if (camera[j].GetDir() != DEFAULT) {
						negdata += camera[j].Filming(neg[i]);
					}
				}
			}
		}
	}

	//�N���E�h���f���C���\�d���̂ŃR�����g�A�E�g
	/*for (int i = 0; i < POS_NUM; i++) {
		if (pos[i].GetisExist()) {
			for (int j = 0; j < 2; j++) {
				if (camera[j].GetDir() != DEFAULT) {
					cloudPos += camera[j].Filming(pos[i]);
				}
			}
		}
	}
	for (int i = 0; i < NEG_NUM; i++) {
		if (neg[i].GetisExist()) {
			for (int j = 0; j < 2; j++) {
				if (camera[j].GetDir() != DEFAULT) {
					cloudNeg += camera[j].Filming(neg[i]);
				}
			}
		}
	}*/

	return 0;
}
int RT::UpdatePostest(People pos[]) {
	double result = 0;
	for (int i = 0; i < 1; i++) {
		if (pos[i].GetisExist()) {//���݂���
			if (ART.GetValue(pos[i].GetNowPos()) == 1) {//�����A�N�Z�X�\���ɂ����
				//cout << "POS_ART_YES" << endl;
				for (int j = 0; j < 2; j++) {
					if (camera[j].GetDir() != DEFAULT) {//�B�e�����������(���ʑS������)
						//result += camera[j].Filming(pos[i]);//�B�e�I
						posdata += camera[j].Filming(pos[i]);//�B�e�I
					}
				}
			}
		}
	}
	//return result;
	return posdata;
}

int RT::UpdateNeg(People neg[]) {
	cout << "UpdateNeg �͕s�\�Ȃ͂��I" << endl;
	int a;
	scanf_s("%d", &a);
	//Pos�ƘA�����邽�߈Ⴄ
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
int RT::nonWork() {
	isWork = false;
	return 0;
}
int RT::Working() {
	isWork = true;
	return 0;
}

RT rt[19];
int RTMngInitialize(int h,int w) {
	for (int i = 0; i < 19; i++) {//���͂��Đ������Ă���mother����J�����Ɉڂ�����
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
		rt[i].nonWork();
		for (int j = 0; j < POS_NUM; j++) {
			if (pos[j].GetisExist()) {//���݂���
				if (rt[i].GetART().GetValue(pos[j].GetNowPos()) == 1) {//�����A�N�Z�X�\���ɂ���Γ��삷��
					rt[i].Working();
				}
			}
		}
		rt[i].Update(pos, neg);
	}
	return 0;
}


double RTMngGetRatio() {
	int possum = 0, negsum = 0;
	for (int i = 0; i < 19; i++) {
		possum += rt[i].Getposdata();
		negsum += rt[i].Getnegdata();
		//cout << i+1 << ":" << rt[i].Getposdata() << endl;
		//cout << i+1 << ":" << rt[i].Getnegdata() << endl;
	}

	return (double)negsum / (negsum + possum);
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
	ofs << "�Z���T�ԍ�,pos,neg,pos+neg" << endl;
	for (int i = 0; i < 19; i++) {
		possum += rt[i].Getposdata();
		negsum += rt[i].Getnegdata();
		ofs << i + 1 << "," << rt[i].Getposdata() << "," << rt[i].Getnegdata() << "," << rt[i].Getposdata() + rt[i].Getnegdata() << endl;
	}
	ofs << "���a," << possum << "," << negsum << "," << "," << setprecision(5) << (double)negsum / (possum + negsum) << endl;
	ofs << "���a(���������)," << possum / 21 << "," << negsum / 21 << "," << "," << setprecision(5) << (double)negsum / (possum + negsum) << endl;
	return 0;
}
int RTMngReset() {
	cloudNeg = 0;
	cloudPos = 0;
	for (int i = 0; i < 19; i++) {
		rt[i].Reset();
	}
	return 0;
}
double CloudRatio() {
	return (double)cloudNeg / (cloudNeg + cloudPos);
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