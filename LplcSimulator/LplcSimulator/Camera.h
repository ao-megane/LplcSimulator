#ifndef CAMERA_H
#define CAMERA_H
#include"Field.h"
#include"Direction.h"

class Camera
{
public:
	Camera();
	~Camera();

private:
	Field workField;
	Direction dir;//撮影方向とは逆にすること
};

#endif // !CAMERA_H




