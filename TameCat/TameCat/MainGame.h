#pragma once
#include "stdafx.h"

class Game
{
public:
	void Init(HWND hWnd);
	void Update();
	void Render();
	void Destroy();
private:
	HWND hWnd;
	void StartRender();
	void EndRender();
	HDC hdc;
	HDC backdc;
	HDC imgdc;
	HBITMAP backbit;
	HBITMAP bgBit;

	RECT clientBox;
};

