#include "stdafx.h"
#include "Object.h"

void CatNfo::init(int cCode,int pX, int pY, int szX, int szY)
{
	SetPos(pX, pY, szX, szY);
	catCode = cCode;
	butlerP = 0;
	loveP = 0;
	hungerP = 50;
	Init_CatloveP(cCode);
}

void CatNfo::init(int cCode, RECT rc)
{
	SetRect(rc);
	catCode = cCode;
	butlerP = 0;
	loveP = 0;
	hungerP = 50;
	Init_CatloveP(cCode);
}

CatDataPkg CatNfo::GetInfo()
{
	CatDataPkg data = { butlerP,loveP,hungerP,catCode };
	return data;
}

