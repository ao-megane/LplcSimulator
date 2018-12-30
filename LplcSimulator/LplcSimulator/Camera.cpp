#include"Camera.h"

Camera::Camera()
{
}

Camera::~Camera()
{
}

int Camera::Initialize(Mother mother) {
	workField = mother.GetRoot();

	if (workField.GetValue(mother.GetBornPos().upDot()) == 1) {//è„
		//cout << "UP:" << Root.GetValue(nowPos.upDot());
		dir = UP;
		return 0;
	}
	if (workField.GetValue(mother.GetBornPos().downDot()) == 1) {//â∫
		//cout << "DOWN:" << Root.GetValue(nowPos.downDot());
		dir = DOWN;
		return 0;
	}
	if (workField.GetValue(mother.GetBornPos().rightDot()) == 1) {//âE
		//cout << "RIGHT:" << Root.GetValue(nowPos.rightDot());
		dir = RIGHT;
		return 0;
	}
	if (workField.GetValue(mother.GetBornPos().leftDot()) == 1) {//ç∂
		//cout << "LEFT:" << Root.GetValue(nowPos.leftDot());
		dir = LEFT;
		return 0;
	}

	return -1;
}

Direction Camera::GetDir() {
	return dir;
}
Field Camera::GetWorkField() {
	return workField;
}

double Camera::Filming(People ppl) {//èuä‘ÅCàÍêlÅCâfÇ¡ÇΩÇ©Ç«Ç§Ç©Ç≠ÇÁÇ¢Ç≈ï‘Ç∑
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
	cout << "dir:" << dir << endl;
	return 0;
}