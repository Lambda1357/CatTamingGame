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

	//�̴ϰ��ӿ� ����
	MinigameRewordCode rewordType;
	int rewordGoldAmount;
	Item* rewordDeco;
	Item* rewordFeed;
	Item* rewordToy;
	int rewordItemAmount;

	Object forestBg, parkBg;

	ItemMap itemData;

	Cat* infoCat;//Ŭ���� ����� ����
	bool isChooseFeed;
	std::map<ItemCode::Feed, Item*>::iterator selectedFeed;
	std::map<ItemCode::Toy, Item*>::iterator selectedToy;

	//��� ����Ʈ
	Object background[LAST_SN];

	//���� UI
	Object boxCatcare;
	Object boxFloat;
	
	Object longButton;
	Object shortButton;
	Object closeButton;
	Object backButton;

	//Ȩ �� UI
	Object boxMoney, boxhairball;
	Object invenButton;
	Object boxInven;
	Object itemInfoBox;
	Object collectionButton;
	Object minigameButton;

	//�÷��� �� UI
	Object boxCollection;
	Object boxInfoCollect;
	Object boxCollectPer;

	//�̴ϰ��� �� UI
	Object startButton;
	Object fishingRod[4];
	PercentBar minigameBar;

	//���� �� UI
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

