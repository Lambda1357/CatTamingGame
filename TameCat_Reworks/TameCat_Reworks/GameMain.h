#pragma once

extern HINSTANCE hInst;

class GameMain
{
private:
	HDC hdc;
	HDC backDC;
	Cat *catlist[20];
	Object background[LAST_SN - 1];
	Object boxSmall;
	Object boxFloat;

	Object startButton;

	int curentCatnum;
	int maxCatCount;
public:
	void Init();
	void Update();
	void Render();
	void Destroy();
	
	BOOL AddCat(TCHAR* imgRoot,CatCode code);

	GameMain();
	~GameMain();
};

