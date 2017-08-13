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
	//���� ���¿� ���� ���°� �����鼭(�巡��), ���� ���°� Ŭ���� �ƴҶ� ����
	if ((isClick_cur == isClick_prv)||(!isClick_cur)) return FALSE; 
	//���콺 ��ġ�� ������Ʈ�� ������ ���� �ȿ� ���� ��� ��
	if ((mousePosY > objRect.top && (objRect.top + objRect.bottom) > mousePosY) &&
		(mousePosX > objRect.left && (objRect.left + objRect.right) > mousePosX))
		return TRUE;
	//�ƴϸ� ����
	else return FALSE;
}
