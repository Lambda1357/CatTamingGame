#include "stdafx.h"
#include "InputManeger.h"

InputManeger* InputManeger::UniqueObj = NULL;

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

void InputManeger::Init()
{
	isClick_cur = FALSE;
	isClick_prv = isClick_cur;
}

void InputManeger::Update()
{
	::GetCursorPos(&mousepos);
	::ScreenToClient(g_Hwnd, &mousepos);

	isClick_prv = isClick_cur;
}

void InputManeger::LbuttonDown()
{
	isClick_cur = TRUE;
}

void InputManeger::LbuttonUp()
{
	isClick_cur = FALSE;
}



BOOL InputManeger::IsHit(Object chkObj)
{
	RECT objRect = chkObj.GetRect();
	//이전 상태와 현재 상태가 같거나(드래그), 현재 상태가 클릭이 아닐때 거짓
	if ((isClick_cur == isClick_prv)||(!isClick_cur)) 
		return FALSE; 
	//마우스 위치가 오브젝트가 차지한 영역 안에 있을 경우 참
	if ((mousepos.y > objRect.top && objRect.bottom > mousepos.y) && (mousepos.x > objRect.left && objRect.right > mousepos.x))
		return TRUE;
	//아니면 거짓
	else return FALSE;
}

BOOL InputManeger::IsHit(RECT objRect)
{
	//이전 상태와 현재 상태가 같거나(드래그), 현재 상태가 클릭이 아닐때 거짓
	if ((isClick_cur == isClick_prv) || (!isClick_cur))
		return FALSE;
	//마우스 위치가 오브젝트가 차지한 영역 안에 있을 경우 참
	if ((mousepos.y > objRect.top && objRect.bottom > mousepos.y) && (mousepos.x > objRect.left && objRect.right > mousepos.x))
		return TRUE;
	//아니면 거짓
	else return FALSE;
}
