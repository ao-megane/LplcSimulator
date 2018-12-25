#pragma once
#include"Camera.h"
#include"Field.h"

class VSS
{
public:
	VSS();
	~VSS();

private:
	Camera cameras[3];
};

VSS::VSS()
{
}

VSS::~VSS()
{
}