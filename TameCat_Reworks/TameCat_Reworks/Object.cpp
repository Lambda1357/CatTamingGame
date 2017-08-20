#include "stdafx.h"
#include "Object.h"


Object::Object()
{
}


Object::~Object()
{
}

void Object::Render(HDC hdc)
{
	imgDC = CreateCompatibleDC(hdc);
	oldBitmap = (HBITMAP)SelectObject(imgDC, myBitmap);

	TransparentBlt(hdc, posX - sizeX, posY - sizeY, sizeX * 2, sizeY * 2, imgDC, 0, 0, sizeX * 2, sizeY * 2, RGB(255, 0, 255));

	SelectObject(imgDC, oldBitmap);
	DeleteDC(imgDC);
}

void Object::Init(TCHAR* imageRoot)
{
	myBitmap = (HBITMAP)LoadImage(NULL, imageRoot, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	if (myBitmap == NULL)
	{
		TCHAR arrmsg[256];
		wsprintf(arrmsg,TEXT("%s"),imageRoot);
		MessageBox(g_Hwnd, arrmsg, TEXT("이미지 로드 실패"), MB_OK);
	}
}

void Object::SetPos(int posX, int posY)
{
	this->posX = posX;
	this->posY = posY;
}

void Object::SetPos(RECT rect)
{
	posX = (rect.left + rect.right) / 2;
	posY = (rect.top + rect.bottom) / 2;
	sizeX = (rect.right - rect.left) / 2;
	sizeY = (rect.bottom - rect.top) / 2;
}

void Object::SetSize(int szX, int szY)
{
	this->sizeX = szX;
	this->sizeY = szY;
}

RECT Object::GetRect()
{
	RECT rect;
	rect.left = posX - sizeX;
	rect.top = posY - sizeY;
	rect.right = posX + sizeX;
	rect.bottom = posY + sizeY;

	return rect;
}

POINT Object::GetPos()
{
	POINT pos = { posX,posY };
	return pos;
}
