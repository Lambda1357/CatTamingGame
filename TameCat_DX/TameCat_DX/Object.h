#pragma once
#include "stdafx.h"

class Object
{
protected:
	texture myImage;
	int x, y;
public:
	void SetPos(int posX, int posY);
	POINT GetPos();
};