#include "stdafx.h"
#include "PercentBar.h"

void PercentBar::Init(TCHAR* bgAddr, TCHAR* FgAddr)
{
	background.Init(bgAddr);
	progressBar.Init(FgAddr);
	
	background.SetSize(600, 75);
	progressBar.SetSize(600,75);
}

void PercentBar::AdjustValue(float percent)
{
	if (percent < 100.0f)
		value = percent;
	else
		value = 100.0f;
}

void PercentBar::CombineValue(float amount)
{
	if (amount <= 0.0f)
	{
		if (value + amount <= 0.0f) value = 0.0f;
		else value += amount;
	}
	else
	{
		if (value + amount >= 100.0f) value = 0.0f;
		else value += amount;
	}
}

void PercentBar::Render(HDC hdc, int posX, int posY)
{
	background.SetPos(posX,posY);
	background.Render(hdc);
	progressBar.Render(hdc, (posX + 600) - ((int)value * 6), posY, (int)value * 6, 75, (int)value * 6, 0, (int)value * 6, 75);
}
