#pragma once
#include "stdafx.h"

class InputMgr
{
private:
	BOOL curClick;
	BOOL prvClick;
	POINT mousePos;
	BOOL SpaceDown;
public:
	void Init();
	void Update(HWND hWnd);
	void Destoy();
	BOOL ButtonChk(UINT msg,WPARAM wParam);
	BOOL ObjHit(Object *hit);
	BOOL SpaceHit();
};