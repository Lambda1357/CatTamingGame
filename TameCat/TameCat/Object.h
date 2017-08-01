#pragma once
#include "stdafx.h"

struct CatDataPkg
{
	int butlerP, loveP, hungerP, catCode;
};

class Object
{
public:
	void SetPos(int pX, int pY, int szX, int szY) { posX = pX, posY = pY, sizeX = szX, sizeY = szY; }
	void SetRect(RECT rc) { sizeX = (rc.left - rc.right) / 2, sizeY = (rc.bottom - rc.top) / 2, posX = rc.right + sizeX, posY = rc.top + sizeY; }
	BOOL SetImg(TCHAR *);
	RECT GetRect();
protected:
	int posX, posY, sizeX, sizeY;
	virtual void ClickAct() = 0;
	TCHAR* imgAdress;
};

class CatNfo : protected Object
{
public:
	void init(TCHAR* imgAdress, int cCode, int pX,int pY, int szX,int szY);
	void init(TCHAR* imgAdress, int cCode, RECT rc);
	CatDataPkg GetInfo();
	void Update();
	void Render();
	void Destroy();
private:
	virtual void ClickAct();
	BOOL addX, addY;
	int Init_CatloveP(int cCode);
	int butlerP, loveP, hungerP,catCode;
	int Max_loveP;
};

