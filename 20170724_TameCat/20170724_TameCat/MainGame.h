#pragma once
#include "stdafx.h"

//
typedef struct CatInfo
{
	//������� ����� ���� ��ġ�� ũ������
	int PosX; int PosY; int SizeX; int SizeY;

	//

	//������� ������ ������ �����ϰ� ����� ���� ��ũ�帮��Ʈȭ
	CatInfo* Next; CatInfo* Prev;
};
typedef struct CatMgr
{

};