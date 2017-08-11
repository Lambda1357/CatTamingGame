#pragma once

extern HINSTANCE hInst;

class Object
{
protected:
	HBITMAP myBitmap; //사용할 이미지의 핸들
	int posX, posY, sizeX, sizeY;

public:
	virtual void Init(TCHAR*);
	void SetPos(int posX, int posY);
	void SetPos(RECT rect);
	void SetSize(int szX, int szY);
	RECT GetRect();
	Object();
	~Object();
	
};

