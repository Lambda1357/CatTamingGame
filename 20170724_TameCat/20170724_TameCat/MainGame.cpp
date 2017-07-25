#include "stdafx.h"
#include "MainGame.h"

void initialize()
{
	m_hdc = GetDC(g_hWnd); //창핸들 받아 DC생성
	//고양이 관리정보 초기화
	butler = { 0 };
	butler.collectPer = 0;
	butler.curCatCnt = 1;
	butler.gold = 1000;
	butler.heirBall = 0;
	butler.maxCatCnt = 10;
	//링크드리스트 준비
	butler.head = new CatInfo;
	butler.teil = new CatInfo;
	//머리 고양이의 초기화
	butler.head->catCode = 1;
	butler.head->max_lvPoint = 200;
	//꼬리 고양이의 초기화
	butler.teil->catCode = 1;
	butler.teil->max_lvPoint = 200;
	//링크드리스트 연결
	butler.head->Next = butler.teil; //머리 다음은 꼬리
	butler.head->Prev = butler.head; //머리의 이전은 머리
	butler.teil->Next = butler.teil; //꼬리의 다음은 꼬리
	butler.teil->Prev = butler.head; //꼬리의 이전은 머리
	//프로그램 세팅된 시간 지정
	startTime = GetTickCount();
	//메인화면으로 레이아웃모드 지정
	lMode = LM_START;
}

void Progress()
{
	switch (lMode)
	{
	case LM_CAT:
		switch (GetTickCount() - startTime)
		{

		}
	}
}

void Render()
{
	//TODO:레이아웃모드에 따라 UI를 그릴것
}

void Release()
{
	ReleaseDC(g_hWnd, m_hdc);
}

int NewCat(CatMgr *mgr, int addCatcode)
{
	
}

void DelCat(CatMgr *mgr, int delCatnum)
{
}

void LayoutMgr(int mx, int my)
{
}
