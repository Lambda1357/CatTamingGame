#include "stdafx.h"
#include "GameMain.h"

//public:

void GameMain::Init()
{
	for (int i = 0; i < 20; i++) catlist[i] = NULL;
	curentCatnum = 0;
	maxCatCount = 10;
}

void GameMain::Update()
{
	switch (SCENEMANEGER->GetScene)
	{
	case SN_START:
		break;
	case SN_HOME:
		for (int i = 0; i < 20; i++)
		{
			if (catlist[i] != NULL) catlist[i]->Update;
		}
		break;
	case SN_COLLECTION:
		break;
	case SN_SHOP:
		break;
	case SN_MINIGAME:
		break;
	case SN_INVENTORY:
		break;
	default:
		break;
	}
}

void GameMain::Render()
{
}

void GameMain::Destroy()
{
	for (int i = 0; i < 20; i++)
	{
		if (catlist[i] != NULL) delete catlist[i];
	}
}

BOOL GameMain::AddCat(TCHAR* imgRoot, CatCode code)
{
	if (curentCatnum <= maxCatCount)
	{
		catlist[curentCatnum] = new Cat;
		catlist[curentCatnum]->Init(imgRoot, code);
		curentCatnum++;
		return FALSE;
	}
	else return TRUE;
}

GameMain::GameMain()
{
}


GameMain::~GameMain()
{
}

//private:
