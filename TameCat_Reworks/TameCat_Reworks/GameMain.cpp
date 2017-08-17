#include "stdafx.h"
#include "GameMain.h"

//public:

void GameMain::Init()
{
	//공통 UI 로드
	boxSmall.Init(TEXT("./resource/UI/boxSmall.bmp"));
	boxSmall.SetPos(489, 300);
	boxSmall.SetSize(225, 125);
	//TODO:boxFloat 로드를 해야함

	//배경파일 로드
	background[SN_START].Init(TEXT("./resource/Background/bg_title.bmp"));
	background[SN_HOME].Init(TEXT("./resource/Background/bg_home.bmp"));
	background[SN_COLLECTION].Init(TEXT("./resource/Background/bg_collection.bmp"));
	background[SN_SHOP].Init(TEXT("./resource/Background/bg_shop.bmp"));
	background[SN_MINIGAME].Init(TEXT("./resource/Background/bg_fishing.bmp"));

	RECT rc = { 420,420,420 + 145,420 + 58 };
	//TODO:startButton.Init(TEXT("이미지경로"));
	startButton.SetPos(rc);

	for (int i = 0; i < 20; i++) catlist[i] = NULL;
	curentCatnum = 0;
	maxCatCount = 10;
}

void GameMain::Update()
{
	switch (SCENEMANEGER->GetScene())
	{
	case SN_START:
		switch (SCENEMANEGER->GetStatus())
		{
		case 0:
			if (INPUTMANEGER->IsHit(startButton))
				SCENEMANEGER->SetScene(SN_HOME);
			break;
		case 1:
			break;
		}
		break;
	case SN_HOME:
		for (int i = 0; i < 20; i++)
		{
			if (catlist[i] != NULL) catlist[i]->Update();
		}
		break;
	case SN_COLLECTION:
		break;
	case SN_SHOP:
		break;
	case SN_MINIGAME:
		break;
	default:
		break;
	}
}

void GameMain::Render()
{
	switch (SCENEMANEGER->GetScene())
	{
	case SN_START:

		break;
	case SN_HOME:
		break;
	case SN_COLLECTION:
		break;
	case SN_SHOP:
		break;
	case SN_MINIGAME:
		break;
	default:
		break;
	}
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
