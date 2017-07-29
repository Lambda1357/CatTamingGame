#pragma once
#include "stdafx.h"

class Game
{
public:
	void Init(HWND hWnd);
	void Update();
	void StartRender();
	void EndRender();
	void Destroy();
private:
	HWND hWnd;

	HDC hdc;
	HDC backdc;
	HDC imgdc;
	HBITMAP backbit;
	HBITMAP bgBit;

	RECT clientBox;
};

