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
	Direction dir;//撮影方向とは逆にすること
};

Camera::Camera()
{
}

Camera::~Camera()
{
}