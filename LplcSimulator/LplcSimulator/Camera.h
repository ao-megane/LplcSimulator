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
	Direction dir;//�B�e�����Ƃ͋t�ɂ��邱��
};

Camera::Camera()
{
}

Camera::~Camera()
{
}