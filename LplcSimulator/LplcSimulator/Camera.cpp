#include"Camera.h"

Camera::Camera()
{
}

Camera::~Camera()
{
}

int Camera::Initialize(Mother mother) {
	workField = mother.GetRoot();
	workField.testDraw();
	Dot center = mother.GetBornPos();

	//cout << "  : " << workField.GetValue(center) << endl;
	//cout << "bornpos : " << center.GetxtoW() << "," << center.GetytoW() << endl;
	cout << "DOWN:" << workField.GetValue(center.downDot()) << endl;
	cout << "UP:" << workField.GetValue(center.upDot()) << endl;
	cout << "RIGHT:" << workField.GetValue(center.rightDot()) << endl;
	cout << "LEFT:" << workField.GetValue(center.leftDot()) << endl;

	if (workField.GetValue(center.upDot()) == 1) {//ã‚Ì‹t
		dir = DOWN;
		return 0;
	}
	if (workField.GetValue(center.downDot()) == 1) {//‰º‚Ì‹t
		dir = UP;
		return 0;
	}
	if (workField.GetValue(center.rightDot()) == 1) {//‰E‚Ì‹t
		dir = LEFT;
		return 0;
	}
	if (workField.GetValue(center.leftDot()) == 1) {//¶‚Ì‹t
		dir = RIGHT;
		return 0;
	}
	workField.testDraw();
	cout << "camera_initialize_error! : " << mother.GetBornPos().GetxtoW() << "," << mother.GetBornPos().GetytoW() << endl;

	return -1;
}

Direction Camera::GetDir() {
	return dir;
}
Field Camera::GetWorkField() {
	return workField;
}

double Camera::Filming(People ppl) {//uŠÔCˆêlC‰f‚Á‚½‚©‚Ç‚¤‚©‚­‚ç‚¢‚Å•Ô‚·
	switch (dir)
	{
	case UP:
		return workField * ppl.GetUpField();
		break;
	case DOWN:
		return workField * ppl.GetDownField();
		break;
	case RIGHT:
		return workField * ppl.GetRightField();
		break;
	case LEFT:
		return workField * ppl.GetLeftField();
		break;
	case DEFAULT:
		cout << "D_FILMIN_ERROR!" << endl;
		break;
	default:
		cout << "FILMIN_ERROR!" << endl;
		break;
	}
}

int Camera::testDraw() {
	workField.testDraw();
	cout << "dir:";
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
	cout << endl;
	return 0;
}