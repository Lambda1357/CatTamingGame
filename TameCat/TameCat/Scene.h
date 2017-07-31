#pragma once
#include <Windows.h>
#include "Button.h"

class Scene
{
protected:
	TCHAR* backgroundBmp;
public:
	virtual void Init() {};
	virtual void Update() {};
	virtual void Render() {};
	virtual void Release() {};

	void SetBackground(TCHAR* adr) { backgroundBmp = adr; };
	TCHAR* GetBackground() { return backgroundBmp; };

};

class StartScene : Scene
{
private:
	Btn_SceneChange startBtn;
	Btn_SceneStatus HowtoBtn;
	short sceneStatus;
public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Release();
};