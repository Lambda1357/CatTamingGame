#pragma once

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
	Cat *catlist[20];

	//����� ������ȸ��
	Cat *infoCat;

	//��� ����Ʈ
	Object background[LAST_SN - 1];

	//UI �ε�
	Object boxSmall;
	Object boxFloat;
	Object boxMoney,boxhairball,boxCollectper;
	
	Object longButton;
	Object shortButton;
	Object closeButton;

	int curentCatnum;
	int maxCatCount;
	int gold, hairball;

	BOOL AddCat(TCHAR* imgRoot, CatCode code);

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

