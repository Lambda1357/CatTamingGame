#pragma once

extern HINSTANCE hInst;

class Object
{
private:
	HBITMAP myBitmap;
	HBITMAP oldBitmap;
	int posX, posY, sizeX, sizeY;

public:
	HDC init(TCHAR*, HDC);
	void SetPos(int posX, int posY);
	void SetPos(RECT rect);
	void SetSize(int szX, int szY);
	int GetImageX();
	int GetImageY();
	Object();
	~Object();
};

