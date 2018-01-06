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

	TransparentBlt(hdc, posX, posY, sizeX, sizeY, imgDC, 0, 0, sizeX, sizeY, RGB(255, 0, 255));

	SelectObject(imgDC, oldBitmap);
	DeleteDC(imgDC);
}

void Object::Init(TCHAR* imageRoot)
{
	myBitmap = (HBITMAP)LoadImage(NULL, imageRoot, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	if (myBitmap == NULL)
	{
		TCHAR arrmsg[256];
		wsprintf(arrmsg, TEXT("%s"), imageRoot);
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
	posX = rect.left;
	posY = rect.top;
	sizeX = rect.right - rect.left;
	sizeY = rect.bottom - rect.top;
}

void Object::SetSize(int szX, int szY)
{
	this->sizeX = szX;
	this->sizeY = szY;
}

RECT Object::GetRect()
{
	RECT rect;
	rect.left = posX;
	rect.top = posY;
	rect.right = posX + sizeX;
	rect.bottom = posY + sizeY;

	return rect;
}

POINT Object::GetPos()
{
	POINT pos = { posX,posY };
	return pos;
}
