#pragma once
#include <Windows.h>

class Scene
{
protected:
	TCHAR* backgroundBmp;
public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;

	void SetBackground(TCHAR*);
	TCHAR* GetBackground();

};

class StartScene : Scene
{
public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Release();
};