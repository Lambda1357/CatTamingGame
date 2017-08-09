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

void InputManeger::ButtonUpdate(UINT msg, WPARAM wParam,LPARAM lParam)
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
