#pragma once
#include "stdafx.h"


class InputMgr
{
private:
	static InputMgr* Imunique;
	BOOL curClick;
	BOOL prvClick;
	POINT mousePos;
	BOOL SpaceDown;
	InputMgr();
public:
	static InputMgr* GetInputMgr();
	void Init();
	void Update(HWND hWnd);
	void Destoy();
	BOOL ButtonChk(UINT msg,WPARAM wParam);
	BOOL ObjHit(Object *hit);
	BOOL SpaceHit();
};

#define INPUTMANEGER InputMgr::GetInputMgr()