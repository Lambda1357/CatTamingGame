#pragma once

extern HINSTANCE hInst;

class Object
{
protected:
	HBITMAP myBitmap; //����� �̹����� �ڵ�
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
	void Render(HDC hdc);
	inline POINT GetSize() { POINT pt = { sizeX,sizeY }; return pt; };
};

