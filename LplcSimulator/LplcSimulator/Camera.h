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
	Direction dir;//�B�e�����Ƃ͋t�ɂ��邱��
};

#endif // !CAMERA_H




