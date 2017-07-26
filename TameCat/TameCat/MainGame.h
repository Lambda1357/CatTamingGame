#pragma once
#include "stdafx.h"

class Game
{
public:
	void init(HWND hWnd);
	void Update();
	void Render();
	void Destroy();
private:
	HDC hdc;
	HWND hWnd;
};

