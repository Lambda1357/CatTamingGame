#include "stdafx.h"
#include "MainGame.h"

void initialize()
{
	m_hdc = GetDC(g_hWnd); //â�ڵ� �޾� DC����
	//����� �������� �ʱ�ȭ
	butler = { 0 };
	butler.collectPer = 0;
	butler.curCatCnt = 1;
	butler.gold = 1000;
	butler.heirBall = 0;
	butler.maxCatCnt = 10;
	//��ũ�帮��Ʈ �غ�
	butler.head = new CatInfo;
	butler.teil = new CatInfo;
	//�Ӹ� ������� �ʱ�ȭ
	butler.head->catCode = 1;
	butler.head->max_lvPoint = 200;
	//���� ������� �ʱ�ȭ
	butler.teil->catCode = 1;
	butler.teil->max_lvPoint = 200;
	//��ũ�帮��Ʈ ����
	butler.head->Next = butler.teil; //�Ӹ� ������ ����
	butler.head->Prev = butler.head; //�Ӹ��� ������ �Ӹ�
	butler.teil->Next = butler.teil; //������ ������ ����
	butler.teil->Prev = butler.head; //������ ������ �Ӹ�
	//���α׷� ���õ� �ð� ����
	startTime = GetTickCount();
	//����ȭ������ ���̾ƿ���� ����
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
	//TODO:���̾ƿ���忡 ���� UI�� �׸���
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
