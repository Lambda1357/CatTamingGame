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

//����� �� ������ ����
typedef struct CatInfo
{
	//������� ����� ���� ��ġ�� ũ������
	int PosX; int PosY; int SizeX; int SizeY;

	//������� ����
	int max_lvPoint;
	int butlerPoint, lovePoint, hungerPoint;
	int catCode;

	//������� ������ ������ �����ϰ� ����� ���� ��ũ�帮��Ʈȭ
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