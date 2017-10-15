#pragma once

#include "stdafx.h"
#include "Singleton.h"


enum SceneNumber
{
	SN_STARTSCREEN,
	SN_CATHOME,
	LAST_SCENENUMBER
};

class Scene
{
protected:
	texture backGround;

public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Destroy();
};

class SceneManager : public Singleton <SceneManager>
{
private:
	Scene* curScene;
	Scene sceneList[LAST_SCENENUMBER];
public:
	void Init();
	void Update();
	void Render();
	void Destroy();
};

#define SCENEMANAGER SceneManager::GetSingleton()
