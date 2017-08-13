#include "stdafx.h"
#include "InputManeger.h"


InputManeger::InputManeger()
{
}


InputManeger::~InputManeger()
{
}

InputManeger * InputManeger::GetUniqueInputMgr()
{
	if (UniqueObj == NULL) UniqueObj = new InputManeger;
	return UniqueObj;
}

void InputManeger::ClickUpdate(UINT msg, WPARAM wParam,LPARAM lParam)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN:
		mousePosX = LOWORD(lParam);
		mousePosY = HIWORD(lParam);
		isClick_prv = isClick_cur;
		isClick_cur = TRUE;
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_SPACE:
			isSpaceDown_prv = isSpaceDown_cur;
			isSpaceDown_cur = TRUE;
			break;
		}
		break;
	default:
		isSpaceDown_prv = isSpaceDown_cur;
		isSpaceDown_cur = FALSE;

		isClick_prv = isClick_cur;
		isClick_cur = FALSE;
		break;
	}
}

BOOL InputManeger::IsHit(Object chkObj)
{
	RECT objRect = chkObj.GetRect();
	//이전 상태와 현재 상태가 같으면서(드래그), 현재 상태가 클릭이 아닐때 거짓
	if ((isClick_cur == isClick_prv)||(!isClick_cur)) return FALSE; 
	//마우스 위치가 오브젝트가 차지한 영역 안에 있을 경우 참
	if ((mousePosY > objRect.top && (objRect.top + objRect.bottom) > mousePosY) &&
		(mousePosX > objRect.left && (objRect.left + objRect.right) > mousePosX))
		return TRUE;
	//아니면 거짓
	else return FALSE;
}
