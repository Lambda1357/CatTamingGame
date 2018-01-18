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
	//���� ���¿� ���� ���°� ���ų�(�巡��), ���� ���°� Ŭ���� �ƴҶ� ����
	if ((isClick_cur == isClick_prv)||(!isClick_cur)) 
		return FALSE; 
	//���콺 ��ġ�� ������Ʈ�� ������ ���� �ȿ� ���� ��� ��
	if ((mousepos.y > objRect.top && objRect.bottom > mousepos.y) && (mousepos.x > objRect.left && objRect.right > mousepos.x))
		return TRUE;
	//�ƴϸ� ����
	else return FALSE;
}

BOOL InputManeger::IsHit(RECT objRect)
{
	//���� ���¿� ���� ���°� ���ų�(�巡��), ���� ���°� Ŭ���� �ƴҶ� ����
	if ((isClick_cur == isClick_prv) || (!isClick_cur))
		return FALSE;
	//���콺 ��ġ�� ������Ʈ�� ������ ���� �ȿ� ���� ��� ��
	if ((mousepos.y > objRect.top && objRect.bottom > mousepos.y) && (mousepos.x > objRect.left && objRect.right > mousepos.x))
		return TRUE;
	//�ƴϸ� ����
	else return FALSE;
}
