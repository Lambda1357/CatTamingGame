#pragma once
#include "ItemMap.h"

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

	Object forestBg, parkBg;

	ItemMap itemData;

	//클릭한 고양이 정보
	Cat* infoCat;

	//배경 리스트
	Object background[LAST_SN];

	//공통 UI
	Object boxCatcare;
	Object boxFloat;
	
	Object longButton;
	Object shortButton;
	Object closeButton;

	//홈 UI
	Object boxMoney, boxhairball;
	Object invenButton;
	Object boxInven;

	//시작 UI
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
public:
	void Init();
	void Update();
	void Render();
	void Destroy();

	GameMain();
	~GameMain();
};

