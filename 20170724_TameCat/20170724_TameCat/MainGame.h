#pragma once
#include "stdafx.h"

enum LAYOUTMODE
{
	LM_START = 0,			//시작 상태
	LM_START_HOWTO,			//시작메뉴에서 게임방법 보는중
	LM_CAT,					//고양이 돌아다니는 창
	LM_CAT_NFO,				//고양이 정보 조회중
	LM_CAT_INV,				//고양이창에서 인벤보는중
	LM_GATCHA,				//가챠 화면
	LM_GATCHA_RSLT,			//가챠 결과보는중
	LM_SHOP,				//상점
	LM_SHOP_YN,				//상점 구매선택중
	LM_COLECTION,			//콜렉션
	LM_COLECTION_NFO,		//콜렉션 고양이 정보보는중
	LM_MINIGAME_STOP,		//미니게임 정지상태
	LM_MINIGAME_RUN,		//미니게임 진행중
	LM_MINIGAME_RSLT		//미니게임 결과
};

//고양이 한 마리의 정보
typedef struct CatInfo
{
	//고양이의 출력을 위한 위치와 크기정보
	int PosX; int PosY; int SizeX; int SizeY;

	//고양이의 정보
	int max_lvPoint;
	int butlerPoint = 0, lovePoint = 0, hungerPoint = 50;
	int catCode;

	//고양이의 생성과 해제를 용이하게 만들기 위해 링크드리스트화
	CatInfo* Next=NULL; CatInfo* Prev=NULL;
};
typedef struct CatMgr
{
	BOOL catBookList[16];
	float collectPer;

	int gold, heirBall;

	int maxCatCnt, curCatCnt;

	CatInfo* head, *teil;
};
 
static HDC m_hdc;
static CatMgr butler;
static LAYOUTMODE lMode;
static int startTime;

extern void initialize();
extern void Progress();
extern void Render();
extern void Release();

extern int NewCat(CatMgr*, int);

extern void DelCat(CatMgr*, int);

extern void LayoutMgr(int, int);