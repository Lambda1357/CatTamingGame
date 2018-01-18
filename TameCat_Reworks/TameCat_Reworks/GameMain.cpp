#include "stdafx.h"
#include "GameMain.h"

HBITMAP hBitmap;

void GameMain::Init()
{
	srand((unsigned)time(NULL));

	gold = 3000;
	hairball = 10;

	//폰트 로드
	AddFontResourceEx(TEXT("./resource/font/gothic.ttf"), FR_NOT_ENUM, NULL); //나눔고딕 Light
	AddFontResourceEx(TEXT("./resource/font/goyang.ttf"), FR_NOT_ENUM, NULL); //고양체
	sizegothic = 10;
	sizegoyang = 20;

	SCENEMANEGER->SetScene(SN_START);
	//공통 UI 로드
	boxSmall.Init(TEXT("./resource/UI/boxCatcare.bmp"));
	boxSmall.SetPos(139, 150);
	boxSmall.SetSize(700, 295);

	boxFloat.Init(TEXT("./resource/UI/boxfloat.bmp"));
	boxFloat.SetPos(489, 300);
	boxFloat.SetSize(350, 150);

	boxMoney.Init(TEXT("./resource/UI/boxMoney.bmp"));
	RECT money = { 69,30,219,90 };
	boxMoney.SetPos(money);

	boxhairball.Init(TEXT("./resource/UI/boxhairball.bmp"));
	RECT hair = { 249,30,399,90 };
	boxhairball.SetPos(hair);

	closeButton.Init(TEXT("./resource/UI/closeButton.bmp"));
	closeButton.SetSize(35, 35);

	//RECT rc = { 420,420,420 + 200,420 + 75 };
	longButton.Init(TEXT("./resource/UI/longButton.bmp"));
	longButton.SetPos(389,463);
	longButton.SetSize(200, 75);
	

	//배경파일 로드
	background[SN_START].Init(TEXT("./resource/Background/bg_title.bmp"));
	background[SN_START].SetPos(0, 0);
	background[SN_START].SetSize(978, 600);

	background[SN_COLLECTION].Init(TEXT("./resource/Background/bg_collection.bmp"));
	background[SN_COLLECTION].SetPos(0, 0);
	background[SN_COLLECTION].SetSize(978, 600);

	background[SN_SHOP].Init(TEXT("./resource/Background/bg_shop.bmp"));
	background[SN_SHOP].SetPos(0, 0);
	background[SN_SHOP].SetSize(978, 600);
/*
	background[SN_MINIGAME].Init(TEXT("./resource/Background/bg_fishing.bmp"));
	background[SN_MINIGAME].SetPos(0, 0);
	background[SN_MINIGAME].SetSize(978, 600);
*/

	background[SN_HOME].Init(TEXT("./resource/Background/bg_home.bmp"));
	background[SN_HOME].SetPos(0, 0);
	background[SN_HOME].SetSize(978, 600);

	



	//고양이리스트 초기화
	for (int i = 0; i < 20; i++) catlist[i] = NULL;
	curentCatnum = 0;
	maxCatCount = 10;

	//기본 고양이 추가
	AddCat(TEXT("./resource/chara/cat_takealook.bmp"), CAT_TAKEALOOK);
	AddCat(TEXT("./resource/chara/cat_heros.bmp"), CAT_HEROS);
	AddCat(TEXT("./resource/chara/cat_fat.bmp"), CAT_FAT);
	AddCat(TEXT("./resource/chara/cat_scotfold.bmp"), CAT_SCOTFOLD);
}

void GameMain::Update()
{
	switch (SCENEMANEGER->GetScene())
	{
	case SN_START:
			if (INPUTMANEGER->IsHit(longButton)) SCENEMANEGER->SetScene(SN_HOME);
			break;
	case SN_HOME:
		for (int i = 0; i < 20; i++)
		{
			if (catlist[i] != NULL) catlist[i]->Update();
		}

		switch (SCENEMANEGER->GetStatus())
		{
		case 0:
			for (int i = 0; i < 20; i++)
			{
				if (catlist[i] != NULL)
					if (INPUTMANEGER->IsHit(*catlist[i]))
					{
						closeButton.SetPos(795, 160);
						infoCat = catlist[i];
						SCENEMANEGER->SetStatus(1);
					}
			}
			break;
		case 1:
			if (INPUTMANEGER->IsHit(closeButton)) SCENEMANEGER->SetStatus(0);
			break;
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
	INPUTMANEGER->Update();
}

void GameMain::Render()
{
	TCHAR textTemp[256];
	static RECT rectTmp;
	hdc = GetDC(g_Hwnd);
	backDC = CreateCompatibleDC(hdc);
	backBit = CreateCompatibleBitmap(hdc, 978, 600);
	hOldbit = (HBITMAP)SelectObject(backDC, backBit);
	SetBkMode(backDC, TRANSPARENT);
	hBitmap = CreateCompatibleBitmap(hdc, 978, 600);
	switch (SCENEMANEGER->GetScene())
	{
	case SN_START:
		background[SN_START].Render(backDC);
		longButton.Render(backDC);

		sizegoyang = 75;
		GetGoyangDC(backDC);
		DrawText(goyangDC, TEXT("START!"), -1, &(longButton.GetRect()), DT_CENTER);
		BitBlt(backDC, longButton.GetRect().left, longButton.GetRect().top, longButton.GetSize().x , longButton.GetSize().y , goyangDC, longButton.GetRect().left, longButton.GetRect().top, SRCAND);
		sizegoyang = 20;
		ReleaseGoyangDC();
		break;
	case SN_HOME:
		background[SN_HOME].Render(backDC);
		for (int i = 0; i < 20; i++)
		{
			if (catlist[i] != NULL)
				catlist[i]->Render(backDC);
		}

		boxMoney.Render(backDC);
		boxhairball.Render(backDC);

		sizegoyang = 30;
		GetGoyangDC(backDC);
		wsprintf(textTemp, TEXT("Gold: %3d"), gold);
		DrawText(goyangDC, textTemp, -1, &(boxMoney.GetRect()), DT_CENTER);

		wsprintf(textTemp, TEXT("털뭉치: %3d"), hairball);
		DrawText(goyangDC, textTemp, -1, &(boxhairball.GetRect()), DT_CENTER);

		BitBlt(backDC, boxMoney.GetRect().left, boxMoney.GetRect().top, boxhairball.GetPos().x+boxhairball.GetSize().x, boxhairball.GetPos().y+boxhairball.GetSize().y,
			goyangDC, boxMoney.GetRect().left, boxMoney.GetRect().top, SRCAND);

		ReleaseGoyangDC();

		switch (SCENEMANEGER->GetStatus())
		{
		case 0:
			//누르기 전 버튼 로드
			break;
		case 1:
			//상태:고양이 정보창
			boxSmall.Render(backDC);
			closeButton.Render(backDC);

			if (_tcslen(infoCat->catName) < 8)
				sizegothic = 25;
			else
				sizegothic = 18;

			GetGothicDC(backDC);
			wsprintf(textTemp, TEXT("%s"), infoCat->catName);
			AdjustRect(&rectTmp, 194, 360, 334, 390);
			DrawText(gothicDC, textTemp, -1, &rectTmp,DT_CENTER);

			wsprintf(textTemp, TEXT("%d / %d"), infoCat->GetLove(), infoCat->GetMaxLove());
			AdjustRect(&rectTmp, 378, 246, 378 + 396, 276);
			DrawText(gothicDC, textTemp, -1, &rectTmp, DT_LEFT);

			wsprintf(textTemp, TEXT("%d%% / 100%%"), infoCat->Gethunger());
			AdjustRect(&rectTmp, 378, 302, 378 + 396, 332);
			DrawText(gothicDC, textTemp, -1, &rectTmp, DT_LEFT);
			
			BitBlt(backDC, boxSmall.GetRect().left, boxSmall.GetRect().top, (boxSmall.GetSize().x) * 2, (boxSmall.GetSize().y) * 2, gothicDC, boxSmall.GetRect().left, boxSmall.GetRect().top, SRCAND);
			ReleaseGothicDC();
			infoCat->PortraitRander(backDC);

			break;
		}
		break;
	case SN_COLLECTION:
		background[SN_COLLECTION].Render(backDC);
		break;
	case SN_SHOP:
		break;
	case SN_MINIGAME:
		break;
	default:
		break;
	}

	BitBlt(hdc, 0, 0, 978, 600, backDC, 0, 0, SRCCOPY);

	SelectObject(backDC, hOldbit);
	DeleteObject(backBit);
	DeleteObject(hBitmap);
	DeleteDC(backDC);
	ReleaseDC(g_Hwnd, hdc);
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

void GameMain::GetGoyangDC(HDC hdc)
{
	RECT rect;
	GetClientRect(g_Hwnd, &rect);
	goyangDC = CreateCompatibleDC(hdc);
	oldGoyangBit = (HBITMAP)SelectObject(goyangDC, hBitmap);
	FillRect(goyangDC, &rect, (HBRUSH)GetStockObject(WHITE_BRUSH));
	hGoyang = CreateFont(sizegoyang, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("Goyang"));
	oldGoyang = (HFONT)SelectObject(goyangDC, hGoyang);
	SetBkMode(goyangDC, TRANSPARENT);
}

void GameMain::GetGothicDC(HDC hdc)
{
	RECT rect;
	GetClientRect(g_Hwnd, &rect);
	gothicDC = CreateCompatibleDC(hdc);
	oldGothicBit = (HBITMAP)SelectObject(gothicDC, hBitmap);
	FillRect(gothicDC, &rect,(HBRUSH)GetStockObject(WHITE_BRUSH));
	hGothic = CreateFont(sizegothic, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("나눔고딕 Light"));
	oldGothic = (HFONT)SelectObject(gothicDC, hGothic);
	SetBkMode(gothicDC, TRANSPARENT);
}

void GameMain::ReleaseGoyangDC()
{
	SelectObject(goyangDC, oldGoyang);
	SelectObject(goyangDC, oldGoyangBit);
	DeleteObject(hGoyang);
	DeleteDC(goyangDC);
}

void GameMain::ReleaseGothicDC()
{
	SelectObject(gothicDC, oldGoyang);
	SelectObject(gothicDC, oldGothicBit);
	DeleteObject(hGothic);
	DeleteDC(gothicDC);
}

GameMain::GameMain()
{
}


GameMain::~GameMain()
{
}

//private:
