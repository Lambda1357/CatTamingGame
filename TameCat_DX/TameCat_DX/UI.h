#pragma once
#include "stdafx.h"

class SmallCashBar
{
private:
	int parameter;
	texture box;
public:
	virtual void Init();
	virtual void Update();
	void Render();
	virtual void Destroy();
};