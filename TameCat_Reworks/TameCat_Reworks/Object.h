#pragma once

extern HINSTANCE hInst;

class Object
{
protected:
	HBITMAP myBitmap; //����� �̹����� �ڵ�
	int posX, posY, sizeX, sizeY;
	void SetPos(int posX, int posY);
	void SetPos(RECT rect);
	void SetSize(int szX, int szY);
public:
	virtual void Init(TCHAR*);
	RECT GetRect();
	Object();
	~Object();
	
};

