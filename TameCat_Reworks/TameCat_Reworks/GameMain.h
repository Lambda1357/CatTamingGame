#pragma once
#include "ItemMap.h"
#include "PercentBar.h"
#include "MinigameRewordCode.h"

extern HINSTANCE hInst;

class GameMain
{
private:
	HDC hdc;
	HDC backDC;

	HDC goyangDC;
	HBITMAP oldGoyangBit;
	HFONT hGoyang;
	HFONT oldGoyang;
	int sizegoyang;

	HDC gothicDC;
	HBITMAP oldGothicBit;
	HFONT hGothic;
	HFONT oldGothic;
	int sizegothic;

	HBITMAP backBit;
	HBITMAP hOldbit;
	Cat* catlist[20];

	//미니게임용 변수
	MinigameRewordCode rewordType;
	int rewordGoldAmount;
	Item* rewordDeco;
	Item* rewordFeed;
	Item* rewordToy;
	int rewordItemAmount;

	Object forestBg, parkBg;

	ItemMap itemData;

	Cat* infoCat;//클릭한 고양이 정보
	bool isChooseFeed;
	std::map<ItemCode::Feed, Item*>::iterator selectedFeed;
	std::map<ItemCode::Toy, Item*>::iterator selectedToy;

	//배경 리스트
	Object background[LAST_SN];

	//공통 UI
	Object boxCatcare;
	Object boxFloat;
	
	Object longButton;
	Object shortButton;
	Object closeButton;
	Object backButton;

	//홈 씬 UI
	Object boxMoney, boxhairball;
	Object invenButton;
	Object boxInven;
	Object itemInfoBox;
	Object collectionButton;
	Object minigameButton;

	//컬렉션 씬 UI
	Object boxCollection;
	Object boxInfoCollect;
	Object boxCollectPer;

	//미니게임 씬 UI
	Object startButton;
	Object fishingRod[4];
	PercentBar minigameBar;

	//시작 씬 UI
	Object logo;

	int curentCatnum;
	int maxCatCount;
	int gold, hairball;

	BOOL AddCat(TCHAR* imgRoot, CatCode code);
	BOOL DelCat(Cat* curCat);

	void GetGoyangDC(HDC hdc);
	void GetGothicDC(HDC hdc);
	void ReleaseGoyangDC();
	void ReleaseGothicDC();

	void SetMinigameReword();
public:
	void Init();
	void Update();
	void Render();
	void Destroy();

	GameMain();
	~GameMain();
};

