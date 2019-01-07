#ifndef CAMERA_H
#define CAMERA_H
#include"Field.h"
#include"Direction.h"
#include"Mother.h"
#include"People.h"

class Camera{
public:
	Camera();
	~Camera();
	int Initialize(Mother mother);
	Direction GetDir();
	Field GetWorkField();
	double Filming(People ppl);//�B�e�I�I
	double FilmingNeg(People neg[]);
	int testDraw();
	void operator = (Camera cam) {
		workField = cam.GetWorkField();
		dir = cam.GetDir();
	}
private:
	Field workField;
	Direction dir;//�B�e�����Ƃ͋t�ɂ��邱��
};

//�J�����}�l�[�W���͂���Ȃ�(RT�����˂�)

#endif // !CAMERA_H




