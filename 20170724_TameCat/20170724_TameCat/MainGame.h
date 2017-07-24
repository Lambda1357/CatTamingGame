#pragma once
#include "stdafx.h"

//
typedef struct CatInfo
{
	//고양이의 출력을 위한 위치와 크기정보
	int PosX; int PosY; int SizeX; int SizeY;

	//

	//고양이의 생성과 해제를 용이하게 만들기 위해 링크드리스트화
	CatInfo* Next; CatInfo* Prev;
};
typedef struct CatMgr
{

};