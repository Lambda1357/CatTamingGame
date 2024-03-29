#include "stdafx.h"
#include "InputMgr.h"

InputMgr* InputMgr::GetInputMgr()
{
	if (Imunique == NULL)
		Imunique = new InputMgr;
	return Imunique;
}

void InputMgr::Init()
{
	curClick = FALSE;
	prvClick = curClick;

	SpaceDown = FALSE;
}

void InputMgr::Update(HWND hWnd)
{
	::GetCursorPos(&mousePos);
	::ScreenToClient(hWnd, &mousePos);
}

void InputMgr::Destoy()
{
	//TODO:여기서 가져온 메모리 공간을 돌려줍니다.
}

BOOL InputMgr::ButtonChk(UINT msg, WPARAM wParam)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN:
		prvClick = curClick;
		curClick = TRUE;
		return 1;
	case WM_LBUTTONUP:
		prvClick = curClick;
		curClick = FALSE;
		return 1;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_SPACE:
			SpaceDown = TRUE;
			break;
		}
		return 1;
	}
	return 0;
}

BOOL InputMgr::ObjHit(Object* hit)
{
	RECT rc = hit->GetRect();
	if (!curClick) return FALSE;
	if (curClick == prvClick) return FALSE;
	if (mousePos.x >= rc.right&&mousePos.x <= rc.left&&mousePos.y >= rc.top&&mousePos.y < rc.bottom)
	{
		return TRUE;
	}
	else return FALSE;
}

BOOL InputMgr::SpaceHit()
{
	if (SpaceDown)
		return TRUE;
	return FALSE;
}
