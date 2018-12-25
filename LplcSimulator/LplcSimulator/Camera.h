#pragma once
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

Camera::Camera()
{
}

Camera::~Camera()
{
}