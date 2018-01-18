#pragma once
#include "windows.h"

inline void AdjustRect(RECT* rct, int l, int t, int r, int b)
{
	rct->left = l;
	rct->top = t;
	rct->right = r;
	rct->bottom = b;
}