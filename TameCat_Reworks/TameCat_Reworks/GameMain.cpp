#include "stdafx.h"
#include "GameMain.h"
#include "Toy.h"
#include "Feed.h"
#include "Deco.h"

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

	boxCatcare.Init(TEXT("./resource/UI/boxCatcare.bmp"));
	boxCatcare.SetPos(139, 150);
	boxCatcare.SetSize(700, 295);

	boxFloat.Init(TEXT("./resource/UI/boxfloat.bmp"));
	boxFloat.SetPos(489, 300);
	boxFloat.SetSize(350, 150);

	closeButton.Init(TEXT("./resource/UI/closeButton.bmp"));
	closeButton.SetSize(35, 35);

	longButton.Init(TEXT("./resource/UI/longButton.bmp"));
	longButton.SetPos(389, 463);
	longButton.SetSize(200, 75);

	//홈 UI
	boxMoney.Init(TEXT("./resource/UI/boxMoney.bmp"));
	RECT money = { 69,30,219,90 };
	boxMoney.SetPos(money);

	boxhairball.Init(TEXT("./resource/UI/boxhairball.bmp"));
	RECT hair = { 249,30,399,90 };
	boxhairball.SetPos(hair);

	invenButton.Init(TEXT("./resource/UI/invenButton.bmp"));
	invenButton.SetPos(838, 30);
	invenButton.SetSize(70, 60);

	boxInven.Init(TEXT("./resource/UI/boxInven.bmp"));
	boxInven.SetPos(139, 153);
	boxInven.SetSize(700, 295);

	itemInfoBox.Init(TEXT("./resource/UI/itemInfoBox.bmp"));
	itemInfoBox.SetPos(189, 500);
	itemInfoBox.SetSize(600, 75);

	//시작 UI
	logo.Init(TEXT("./resource/UI/logo.bmp"));
	logo.SetPos(339, 40);
	logo.SetSize(300, 220);

	//배경파일 로드
	background[SN_START].Init(TEXT("./resource/Background/bg_title.bmp"));
	background[SN_START].SetPos(0, 0);
	background[SN_START].SetSize(978, 600);

	background[SN_HOME].Init(TEXT("./resource/Background/bg_home.bmp"));
	background[SN_HOME].SetPos(0, 0);
	background[SN_HOME].SetSize(978, 600);

	background[SN_COLLECTION].Init(TEXT("./resource/Background/bg_collection.bmp"));
	background[SN_COLLECTION].SetPos(0, 0);
	background[SN_COLLECTION].SetSize(978, 600);

	background[SN_SHOP].Init(TEXT("./resource/Background/bg_shop.bmp"));
	background[SN_SHOP].SetPos(0, 0);
	background[SN_SHOP].SetSize(978, 600);

	background[SN_MINIGAME].Init(TEXT("./resource/Background/bg_fishing.bmp"));
	background[SN_MINIGAME].SetPos(0, 0);
	background[SN_MINIGAME].SetSize(978, 600);

	//고양이리스트 초기화
	for (int i = 0; i < 20; i++) catlist[i] = NULL;
	curentCatnum = 0;
	maxCatCount = 10;

	//기본 고양이 추가
	AddCat(TEXT("./resource/chara/cat_takealook.bmp"), CAT_TAKEALOOK);
	AddCat(TEXT("./resource/chara/cat_heros.bmp"), CAT_HEROS);
	AddCat(TEXT("./resource/chara/cat_fat.bmp"), CAT_FAT);
	AddCat(TEXT("./resource/chara/cat_scotfold.bmp"), CAT_SCOTFOLD);

	SCENEMANEGER->SetThemeTo(ItemCode::Deco::THEMEHOME);
	forestBg.Init(_T("./resource/Background/bg_forest.bmp"));
	forestBg.SetPos(0, 0);
	forestBg.SetSize(978, 600);
	parkBg.Init(_T("./resource/Background/bg_park.bmp"));
	parkBg.SetPos(0, 0);
	parkBg.SetSize(978, 600);

	//아이템 배경 로드
	Item::BgBoxInit(_T("./resource/item/bgBox.bmp"));

	//데코 아이템 로드
	for (int i = 0; i != (int)ItemCode::Deco::LAST_DECO; i++)
	{
		ItemCode::Deco index = (ItemCode::Deco)i;
		itemData.deco[index] = new Deco(index);
		switch (index)
		{
		case ItemCode::Deco::THEMEPARK:
			itemData.deco[index]->Init(_T("./resource/Item/itemThemePark.bmp"));
			break;
		case ItemCode::Deco::THEMEFOREST:
			itemData.deco[index]->Init(_T("./resource/Item/itemThemeForest.bmp"));
			break;
		case ItemCode::Deco::THEMEHOME:
			itemData.deco[index]->Init(_T("./resource/item/itemThemeHome.bmp"));
			break;
		}
	}

	//장난감 아이템 로드
	for (int i = 0; i != (int)ItemCode::Toy::LAST_TOY; i++)
	{
		ItemCode::Toy index = (ItemCode::Toy)i;
		itemData.toy[index] = new Toy(index);
		switch (index)
		{
		case ItemCode::Toy::DOLPHINDOLL:
			itemData.toy[index]->Init(_T("./resource/item/itemDolphinDoll.bmp"));
			break;
		case ItemCode::Toy::RATTOY:
			itemData.toy[index]->Init(_T("./resource/item/itemRatToy.bmp"));
			break;
		case ItemCode::Toy::FEATHERROD:
			itemData.toy[index]->Init(_T("./resource/item/itemFeatherRod.bmp"));
			break;
		case ItemCode::Toy::TOWERBALL:
			itemData.toy[index]->Init(_T("./resource/item/itemTowerBall.bmp"));
			break;
		case ItemCode::Toy::MOBILETOY:
			itemData.toy[index]->Init(_T("./resource/item/itemMobileToy.bmp"));
			break;
		case ItemCode::Toy::SCRATCHER:
			itemData.toy[index]->Init(_T("./resource/item/itemScratcher.bmp"));
			break;
		case ItemCode::Toy::CATTOWER:
			itemData.toy[index]->Init(_T("./resource/item/itemCatTower.bmp"));
			break;
		case ItemCode::Toy::CUSHION:
			itemData.toy[index]->Init(_T("./resource/item/itemCushion.bmp"));
			break;
		}
	}

	//먹이 아이템 로드
	for (int i = 0; i != (int)ItemCode::Feed::LAST_FEED; i++)
	{
		ItemCode::Feed index = (ItemCode::Feed)i;
		itemData.feed[index] = new Feed(index);
		switch (index)
		{
		case ItemCode::Feed::MILK:
			itemData.feed[index]->Init(_T("./resource/item/itemMilk.bmp"));
			break;
		case ItemCode::Feed::FEED:
			itemData.feed[index]->Init(_T("./resource/item/itemFeed.bmp"));
			break;
		case ItemCode::Feed::CAN:
			itemData.feed[index]->Init(_T("./resource/item/itemCan.bmp"));
			break;
		case ItemCode::Feed::SUSHI:
			itemData.feed[index]->Init(_T("./resource/item/itemSushi.bmp"));
			break;
		case ItemCode::Feed::CHUR:
			itemData.feed[index]->Init(_T("./resource/item/itemChur.bmp"));
			break;
		}
	}
}

void GameMain::Update()
{
	RECT tmpHitbox;
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
			//기본 상태의 입력 체크
			if (INPUTMANEGER->IsHit(invenButton))
			{
				closeButton.SetPos(795, 160);
				SCENEMANEGER->SetStatus(2);
				break;
			}
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
			//고양이 정보창 상태의 입력 체크
			if (INPUTMANEGER->IsHit(closeButton)) SCENEMANEGER->SetStatus(0);
			AdjustRect(&tmpHitbox, 689, 358, 789, 398); //내보내기 버튼
			if (INPUTMANEGER->IsHit(tmpHitbox))
			{
				DelCat(infoCat);
				SCENEMANEGER->SetStatus(0);
			}
			break;

		case 2:
			//인벤토리 상태의 입력 체크
			if (INPUTMANEGER->IsHit(closeButton)) SCENEMANEGER->SetStatus(0);

			//데코 아이템 사용
			for (auto it = itemData.deco.begin(); it != itemData.deco.end(); it++)
			{
				if (INPUTMANEGER->IsHit(*(it->second)))
				{
					if (it->second->GetCount() > 0) it->second->UseItem();
				}
			}

			//사료 아이템 선택
			for (auto it = itemData.feed.begin(); it != itemData.feed.end(); it++)
			{
				if (INPUTMANEGER->IsHit(*(it->second)))
				{
					if (it->second->GetCount() > 0)
					{
						selectedFeed = it;
						isChooseFeed = true;
						closeButton.SetPos(734, 520);
						selectedFeed->second->SetPos(206, 513);
						SCENEMANEGER->SetStatus(3);
					}
				}
			}

			//장난감 아이템 선택
			for (auto it = itemData.toy.begin(); it != itemData.toy.end(); it++)
			{
				if (INPUTMANEGER->IsHit(*(it->second)))
				{
					if (it->second->GetCount() > 0)
					{
						selectedToy = it;
						isChooseFeed = false;
						closeButton.SetPos(734, 520);
						selectedToy->second->SetPos(206, 513);
						SCENEMANEGER->SetStatus(3);
					}
				}
			}
			break;
		case 3:
			if (isChooseFeed)
			{
				if (INPUTMANEGER->IsHit(closeButton))
				{
					SCENEMANEGER->SetStatus(2);
					closeButton.SetPos(795, 160);
					break;
				}
				else
				{
					for (int i = 0; i < 20; i++)
					{
						if (catlist[i] != NULL)
							if (INPUTMANEGER->IsHit(*catlist[i]))
							{
								selectedFeed->second->UseItem(catlist[i]);
								SCENEMANEGER->SetStatus(0);
							}
					}
				}
			}

			//TODO:인벤토리 상태에서 누른 장난감 아이템을 고양이를 눌러 체크하도록 만들기
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
	int tmp;

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
		logo.Render(backDC);

		sizegoyang = 75;
		GetGoyangDC(backDC);
		DrawText(goyangDC, TEXT("START!"), -1, &(longButton.GetRect()), DT_CENTER);
		BitBlt(backDC, longButton.GetRect().left, longButton.GetRect().top, longButton.GetSize().x, longButton.GetSize().y, goyangDC, longButton.GetRect().left, longButton.GetRect().top, SRCAND);
		sizegoyang = 20;
		ReleaseGoyangDC();
		break;
	case SN_HOME:
		switch (SCENEMANEGER->GetCurTheme())
		{
		case ItemCode::Deco::THEMEPARK:
			parkBg.Render(backDC);
			break;
		case ItemCode::Deco::THEMEFOREST:
			forestBg.Render(backDC);
			break;
		case ItemCode::Deco::THEMEHOME:
			background[SN_HOME].Render(backDC);
			break;
		}
		for (int i = 0; i < 20; i++)
		{
			if (catlist[i] != NULL)
				catlist[i]->Render(backDC);
		}

		boxMoney.Render(backDC);
		boxhairball.Render(backDC);
		invenButton.Render(backDC);

		sizegoyang = 30;
		GetGoyangDC(backDC);
		wsprintf(textTemp, TEXT("       %3d"), gold);
		DrawText(goyangDC, textTemp, -1, &(boxMoney.GetRect()), DT_CENTER);

		wsprintf(textTemp, TEXT("       %3d"), hairball);
		DrawText(goyangDC, textTemp, -1, &(boxhairball.GetRect()), DT_CENTER);

		BitBlt(backDC, boxMoney.GetRect().left, boxMoney.GetRect().top, boxhairball.GetPos().x + boxhairball.GetSize().x, boxhairball.GetPos().y + boxhairball.GetSize().y,
			goyangDC, boxMoney.GetRect().left, boxMoney.GetRect().top, SRCAND);

		ReleaseGoyangDC();

		switch (SCENEMANEGER->GetStatus())
		{
		case 1:
			//상태:고양이 정보창
			boxCatcare.Render(backDC);
			closeButton.Render(backDC);

			//이름 길이로 글씨 사이즈 가변화
			if (_tcslen(infoCat->catName) < 8)
				sizegothic = 25;
			else
				sizegothic = 18;

			GetGothicDC(backDC);
			wsprintf(textTemp, TEXT("%s"), infoCat->catName);
			AdjustRect(&rectTmp, 194, 360, 334, 390);
			DrawText(gothicDC, textTemp, -1, &rectTmp, DT_CENTER);

			wsprintf(textTemp, TEXT("%d / %d"), infoCat->GetLove(), infoCat->GetMaxLove());
			AdjustRect(&rectTmp, 378, 246, 378 + 396, 276);
			DrawText(gothicDC, textTemp, -1, &rectTmp, DT_LEFT);

			wsprintf(textTemp, TEXT("%d%% / 100%%"), infoCat->Gethunger());
			AdjustRect(&rectTmp, 378, 302, 378 + 396, 332);
			DrawText(gothicDC, textTemp, -1, &rectTmp, DT_LEFT);

			BitBlt(backDC, boxCatcare.GetRect().left, boxCatcare.GetRect().top, (boxCatcare.GetSize().x) * 2, (boxCatcare.GetSize().y) * 2, gothicDC, boxCatcare.GetRect().left, boxCatcare.GetRect().top, SRCAND);
			ReleaseGothicDC();
			infoCat->PortraitRander(backDC);

			break;
		case 2:
			boxInven.Render(backDC);
			closeButton.Render(backDC);
			sizegothic = 16;
			GetGothicDC(backDC);
			tmp = 0;

			for (auto iter = itemData.deco.begin(); iter != itemData.deco.end(); iter++)
			{
				iter->second->RenderInven(backDC);
				if (iter->second->GetCount() == 100) wsprintf(textTemp, _T("99+"));
				else wsprintf(textTemp, _T("%d"), iter->second->GetCount());
				AdjustRect(&rectTmp, 250 + (70 * tmp), 416, 280 + (70 * tmp), 430);
				DrawText(gothicDC, textTemp, -1, &rectTmp, DT_RIGHT);
				tmp++;
			}

			tmp = 0;
			for (auto iter = itemData.feed.begin(); iter != itemData.feed.end(); iter++)
			{
				iter->second->RenderInven(backDC);

				if (iter->second->GetCount() == -1) wsprintf(textTemp, _T("99+"));
				else wsprintf(textTemp, _T("%d"), iter->second->GetCount());
				AdjustRect(&rectTmp, 250 + (70 * tmp), 255, 280 + (70 * tmp), 271);
				DrawText(gothicDC, textTemp, -1, &rectTmp, DT_RIGHT);
				tmp++;
			}
			tmp = 0;
			for (auto iter = itemData.toy.begin(); iter != itemData.toy.end(); iter++)
			{
				iter->second->RenderInven(backDC);

				if (iter->second->GetCount() == -1) wsprintf(textTemp, _T("99+"));
				else wsprintf(textTemp, _T("%d"), iter->second->GetCount());
				AdjustRect(&rectTmp, 250 + (70 * tmp), 338, 280 + (70 * tmp), 354);
				DrawText(gothicDC, textTemp, -1, &rectTmp, DT_RIGHT);
				tmp++;
			}

			BitBlt(backDC, boxInven.GetRect().left, boxInven.GetRect().top, boxInven.GetRect().right, boxInven.GetRect().bottom, gothicDC, boxInven.GetPos().x, boxInven.GetPos().y, SRCAND);
			ReleaseGothicDC();
			break;
		case 3:
			sizegothic = 30;
			GetGoyangDC(backDC);
			itemInfoBox.Render(backDC);
			closeButton.Render(backDC);
			AdjustRect(&rectTmp, 276, 523, 716, 553);
			DrawText(goyangDC, _T("아이템을 사용할 고양이를 클릭하세요"), -1, &rectTmp, DT_LEFT);
			BitBlt(backDC, 276, 523, 716, 553, goyangDC, 276, 523, SRCAND);
			if (isChooseFeed)
			{
				selectedFeed->second->Render(backDC);
			}
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

BOOL GameMain::DelCat(Cat* curCat)
{
	bool isFinding = true;

	for (int i = 0; i <= curentCatnum; i++)
	{
		if (isFinding)
		{
			if (catlist[i] == curCat)
			{
				delete(catlist[i]);
				isFinding = false;
			}
		}
		else
		{
			catlist[i - 1] = catlist[i];
		}
	}
	catlist[curentCatnum] = NULL;
	curentCatnum - 1;

	return TRUE;
}

void GameMain::GetGoyangDC(HDC hdc)
{
	RECT rect;
	GetClientRect(g_Hwnd, &rect);
	goyangDC = CreateCompatibleDC(hdc);
	oldGoyangBit = (HBITMAP)SelectObject(goyangDC, hBitmap);
	FillRect(goyangDC, &rect, (HBRUSH)GetStockObject(WHITE_BRUSH));
	hGoyang = CreateFont(sizegoyang, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, NONANTIALIASED_QUALITY, VARIABLE_PITCH | FF_DONTCARE, TEXT("Goyang"));
	oldGoyang = (HFONT)SelectObject(goyangDC, hGoyang);
	SetBkMode(goyangDC, TRANSPARENT);
}

void GameMain::GetGothicDC(HDC hdc)
{
	RECT rect;
	GetClientRect(g_Hwnd, &rect);
	gothicDC = CreateCompatibleDC(hdc);
	oldGothicBit = (HBITMAP)SelectObject(gothicDC, hBitmap);
	FillRect(gothicDC, &rect, (HBRUSH)GetStockObject(WHITE_BRUSH));
	hGothic = CreateFont(sizegothic, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, NONANTIALIASED_QUALITY, VARIABLE_PITCH | FF_ROMAN, TEXT("나눔고딕 Light"));
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
