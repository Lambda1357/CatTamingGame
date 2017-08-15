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
	HDC imgDC = GetDC(g_Hwnd);
	HBITMAP oldBitmap = (HBITMAP)SelectObject(imgDC, myBitmap);

	TransparentBlt(hdc, posX - sizeX, posY - sizeY, sizeX * 2, sizeY * 2, imgDC, 0, 0, sizeX * 2, sizeY * 2, RGB(255, 0, 255));

	SelectObject(imgDC, oldBitmap);
	ReleaseDC(g_Hwnd, imgDC);
}

void Object::Init(TCHAR* imageRoot)
{
	myBitmap = (HBITMAP)LoadImage(NULL, imageRoot, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
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
	rect.right = sizeX * 2;
	rect.top = sizeY * 2;
	return rect;
}
