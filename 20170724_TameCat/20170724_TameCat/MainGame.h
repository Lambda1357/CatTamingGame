#pragma once
#include "stdafx.h"

enum LAYOUTMODE
{
	LM_START = 0,
	LM_START_HOWTO,
	LM_CAT,
	LM_CAT_NFO,
	LM_CAT_INV,
	LM_GATCHA,
	LM_GATCHA_RSLT,
	LM_SHOP,
	LM_SHOP_YN,
	LM_COLECTION,
	LM_COLECTION_NFO,
	LM_MINIGAME_STOP,
	LM_MINIGAME_RUN,
	LM_MINIGAME_RSLT
};

//고양이 한 마리의 정보
typedef struct CatInfo
{
	//고양이의 출력을 위한 위치와 크기정보
	int PosX; int PosY; int SizeX; int SizeY;

	//고양이의 정보
	int max_lvPoint;
	int butlerPoint, lovePoint, hungerPoint;
	int catCode;

	//고양이의 생성과 해제를 용이하게 만들기 위해 링크드리스트화
	CatInfo* Next; CatInfo* Prev;
};
typedef struct CatMgr
{
	BOOL catBookList[16];
	float collectPer;

	int gold, heirBall;

	int maxCatCnt, curCatCnt;

	CatInfo* head, teil;
};

extern void NewCat(CatMgr*, int);

extern void DelCat(CatMgr*, int);