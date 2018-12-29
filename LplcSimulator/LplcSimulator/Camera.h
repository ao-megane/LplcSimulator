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
	Direction dir;//ŽB‰e•ûŒü‚Æ‚Í‹t‚É‚·‚é‚±‚Æ
};

#endif // !CAMERA_H




