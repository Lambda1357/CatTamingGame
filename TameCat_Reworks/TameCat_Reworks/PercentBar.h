#pragma once
#include "stdafx.h"

class PercentBar : private Object
{
private:
	Object background;
	Object progressBar;
	float value = 50.0f;

public:
	void Init(TCHAR* bgAddr,TCHAR* FgAddr);
	void AdjustValue(float percent);
	void CombineValue(float amount);
	void Render(HDC hdc, int posX, int posY);
};