#include"Camera.h"

Camera::Camera(){
	workField.Initialize(0, 0);
	dir = DEFAULT;
}

Camera::~Camera()
{
}

int Camera::Initialize(Mother mother) {
	workField = mother.GetRoot();
	//workField.testDraw();
	Dot center;
	center = mother.GetBornPos();
	//center = center.reverseDot();
	dir = DEFAULT;

	//cout << "  : " << workField.GetValue(center) << endl;
	/*cout << "bornpos : " << center.GetxtoW() << "," << center.GetytoW() << endl;
	cout << "bornpos : " << workField.GetValue(center) << endl;
	cout << "DOWN:" << workField.GetValue(center.downDot()) << endl;
	cout << "UP:" << workField.GetValue(center.upDot()) << endl;
	cout << "RIGHT:" << workField.GetValue(center.rightDot()) << endl;
	cout << "LEFT:" << workField.GetValue(center.leftDot()) << endl;*/

	if (workField.GetValue(center.upDot()) == 1) {//ã‚Ì‹t
		dir = DOWN;
		cout << "DOWN" << endl;
		return 0;
	}
	if (workField.GetValue(center.downDot()) == 1) {//‰º‚Ì‹t
		dir = UP;
		cout << "UP" << endl;
		return 0;
	}
	if (workField.GetValue(center.rightDot()) == 1) {//‰E‚Ì‹t
		dir = LEFT;
		cout << "LEFT" << endl;
		return 0;
	}
	if (workField.GetValue(center.leftDot()) == 1) {//¶‚Ì‹t
		dir = RIGHT;
		cout << "RIGHT" << endl;
		return 0;
	}
	//workField.testDraw();
	//cout << "camera_initialize_error! : " << center.GetxtoW() << "," << center.GetytoW() << endl;

	return -1;
}

Direction Camera::GetDir() {
	return dir;
}
Field Camera::GetWorkField() {
	return workField;
}

double Camera::Filming(People ppl) {//uŠÔCˆêlC‰f‚Á‚½‚©‚Ç‚¤‚©‚­‚ç‚¢‚Å•Ô‚·
	int a;
	switch (dir)
	{
	case UP:
		//cout << "UP_FILMING" << endl;
		return workField * ppl.GetUpFieldAd();
		break;
	case DOWN:
		//cout << "DOWN_FILMING" << endl;
		return workField * ppl.GetDownFieldAd();
		break;
	case RIGHT:
		//cout << "RIGHT_FILMING" << endl;
		return workField * ppl.GetRightFieldAd();
		break;
	case LEFT:
		//cout << "LEFT_FILMING" << endl;
		return workField * ppl.GetLeftFieldAd();
		break;
	case DEFAULT:
		cout << "DEF_FILMING_ERROR!" << endl;
		scanf_s("%d", &a);
		return -1;
		break;
	default:
		cout << "FILMING_ERROR!" << endl;
		scanf_s("%d", &a);
		return -1;
		break;
	}
}
double Camera::FilmingNeg(People neg[]) {
	double result = 0;
	for (int i = 0; i < NEG_NUM; i++) {
		if (neg[i].GetisExist()) {
			result += Filming(neg[i]);
		}
	}
	return result;
}

int Camera::testDraw() {
	//workField.testDraw();
	//workField.eachtestDraw();
	cout << "camera_dir:";
	switch (dir)
	{
	case UP:
		cout << "UP" << endl;
		break;
	case DOWN:
		cout << "DOWN" << endl;
		break;
	case RIGHT:
		cout << "RIGHT" << endl;
		break;
	case LEFT:
		cout << "LEFT" << endl;
		break;
	case DEFAULT:
		cout << "DEFAULT" << endl;
		break;
	default:
		cout << "CAMERA_DIR_ERROR" << endl;
		break;
	}
	//cout << endl;
	return 0;
}