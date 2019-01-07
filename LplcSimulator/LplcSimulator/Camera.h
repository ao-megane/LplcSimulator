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
	double Filming(People ppl);//撮影！！
	double FilmingNeg(People neg[]);
	int testDraw();
	void operator = (Camera cam) {
		workField = cam.GetWorkField();
		dir = cam.GetDir();
	}
private:
	Field workField;
	Direction dir;//撮影方向とは逆にすること
};

//カメラマネージャはいらない(RTが兼ねる)

#endif // !CAMERA_H




