#pragma once

extern HINSTANCE hInst;

class GameMain
{
private:
	HDC hdc;
	HDC memDC;

public:
	void Init();
	void Update();
	void Render();
	void Destroy();



	GameMain();
	~GameMain();
};

