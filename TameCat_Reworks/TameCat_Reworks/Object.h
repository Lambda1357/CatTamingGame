#pragma once

extern HINSTANCE hInst;

class Object
{
protected:
	HBITMAP myBitmap; //사용할 이미지의 핸들
	int posX, posY, sizeX, sizeY;
	HDC imgDC;
	HBITMAP oldBitmap;
public:
	void SetPos(int posX, int posY);
	void SetPos(RECT rect);
	void SetSize(int szX, int szY);
	virtual void Init(TCHAR*);
	RECT GetRect();
	POINT GetPos();
	Object();
	~Object();
	virtual void Render(HDC hdc);
	void Render(HDC hdc, int xDest, int yDest, int wDest, int hDest, int xSrc, int ySrc, int wSrc, int hSrc);
	inline POINT GetSize() { POINT pt = { sizeX,sizeY }; return pt; };
};

