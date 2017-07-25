#pragma once
#include "stdafx.h"

enum LAYOUTMODE
{
	LM_START = 0,			//���� ����
	LM_START_HOWTO,			//���۸޴����� ���ӹ�� ������
	LM_CAT,					//����� ���ƴٴϴ� â
	LM_CAT_NFO,				//����� ���� ��ȸ��
	LM_CAT_INV,				//�����â���� �κ�������
	LM_GATCHA,				//��í ȭ��
	LM_GATCHA_RSLT,			//��í ���������
	LM_SHOP,				//����
	LM_SHOP_YN,				//���� ���ż�����
	LM_COLECTION,			//�ݷ���
	LM_COLECTION_NFO,		//�ݷ��� ����� ����������
	LM_MINIGAME_STOP,		//�̴ϰ��� ��������
	LM_MINIGAME_RUN,		//�̴ϰ��� ������
	LM_MINIGAME_RSLT		//�̴ϰ��� ���
};

//����� �� ������ ����
typedef struct CatInfo
{
	//������� ����� ���� ��ġ�� ũ������
	int PosX; int PosY; int SizeX; int SizeY;

	//������� ����
	int max_lvPoint;
	int butlerPoint = 0, lovePoint = 0, hungerPoint = 50;
	int catCode;

	//������� ������ ������ �����ϰ� ����� ���� ��ũ�帮��Ʈȭ
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