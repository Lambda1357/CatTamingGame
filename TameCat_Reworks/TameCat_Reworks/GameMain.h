#pragma once

extern HINSTANCE hInst;

class GameMain
{
private:
	HDC hdc;
	HDC memDC;
	Cat *catlist[20];
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

