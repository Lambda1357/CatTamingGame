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
	boxSmall.Init(TEXT("./resource/UI/boxSmall.bmp"));
	boxSmall.SetPos(489, 300);
	boxSmall.SetSize(225, 125);

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
	closeButton.SetSize(17, 17);

	//RECT rc = { 420,420,420 + 200,420 + 75 };
	longButton.Init(TEXT("./resource/UI/longButton.bmp"));
	longButton.SetPos(489,500);
	longButton.SetSize(100, 37);
	

	//배경파일 로드
	background[SN_START].Init(TEXT("./resource/Background/bg_title.bmp"));
	background[SN_START].SetPos(489, 300);
	background[SN_START].SetSize(489, 300);

	background[SN_COLLECTION].Init(TEXT("./resource/Background/bg_collection.bmp"));
	background[SN_COLLECTION].SetPos(489, 300);
	background[SN_COLLECTION].SetSize(489, 300);

	background[SN_SHOP].Init(TEXT("./resource/Background/bg_shop.bmp"));
	background[SN_SHOP].SetPos(489, 300);
	background[SN_SHOP].SetSize(489, 300);
/*
	background[SN_MINIGAME].Init(TEXT("./resource/Background/bg_fishing.bmp"));
	background[SN_MINIGAME].SetPos(489, 300);
	background[SN_MINIGAME].SetSize(489, 300);
*/

	background[SN_HOME].Init(TEXT("./resource/Background/bg_home.bmp"));
	background[SN_HOME].SetPos(489, 300);
	background[SN_HOME].SetSize(489, 300);

	



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
	POINT temp;
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
						temp = boxSmall.GetPos();
						closeButton.SetPos(temp.x + 200, temp.y - 100);
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
	TCHAR boxSmallMsg[256];
	TCHAR moneyTmp[24];
	TCHAR hairballTmp[24];
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
		DrawText(goyangDC, TEXT("Start!"), -1, &(longButton.GetRect()), DT_CENTER);
		BitBlt(backDC, longButton.GetRect().left, longButton.GetRect().top, longButton.GetSize().x * 2, longButton.GetSize().y * 2, goyangDC, longButton.GetRect().left, longButton.GetRect().top, SRCAND);
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
		GetGoyangDC(backDC);
		sizegoyang = 40;
		wsprintf(moneyTmp, TEXT("Gold: %3d"), gold);
		DrawText(goyangDC, moneyTmp, -1, &(boxMoney.GetRect()), DT_CENTER);
		wsprintf(hairballTmp, TEXT("털뭉치: %3d"), hairball);
		DrawText(goyangDC, hairballTmp, -1, &(boxhairball.GetRect()), DT_CENTER);
		ReleaseGoyangDC();
		sizegoyang = 20;

		BitBlt(backDC, boxMoney.GetRect().left, boxMoney.GetRect().top, boxMoney.GetSize().x*2 , boxMoney.GetSize().y*2, goyangDC, boxMoney.GetRect().left, boxMoney.GetRect().top, SRCAND);
		boxMoney.Render(backDC);
		boxhairball.Render(backDC);
		switch (SCENEMANEGER->GetStatus())
		{
		case 0:
			//누르기 전 버튼 로드
			break;
		case 1:
			//상태:고양이 정보창
			boxSmall.Render(backDC);
			closeButton.Render(backDC);
			GetGoyangDC(backDC);
			wsprintf(boxSmallMsg, TEXT("\n   고양이 이름: %s\n   허기: %d%%\n   애정도: %d / %d"), infoCat->catName,infoCat->Gethunger(),infoCat->GetLove(),infoCat->GetMaxLove());
			DrawText(goyangDC, boxSmallMsg, -1, &(boxSmall.GetRect()), DT_TOP | DT_LEFT | DT_WORDBREAK);
			BitBlt(backDC, boxSmall.GetRect().left, boxSmall.GetRect().top, (boxSmall.GetSize().x) * 2, (boxSmall.GetSize().y) * 2, goyangDC, boxSmall.GetRect().left, boxSmall.GetRect().top, SRCAND);
			ReleaseGoyangDC();
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
	hGoyang = CreateFont(sizegothic, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("나눔고딕 Light"));
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
