#pragma once
#include "Scene.h"

enum SceneCode
{
	SN_START=0,
	SN_HOME,
	SN_COLLECTION,
	SN_SHOP,
	SN_MINIGAME,
	SN_INVENTORY,
	SN_IMLAST //1 »« °ªÀÌ ¾ÀÀÇ °¹¼ö
};

class SceneManager
{
private:
	static SceneManager* uniqueSceneMgr;
	Scene* curScene;
	Scene* SceneList[SN_IMLAST - 1];
	SceneManager() {};
public:
	static SceneManager* GetScenemgr();
	void Init();
	void Update();
	void Render();
	void Destory();

	void SetCurScene(SceneCode sc);
};

#define SCENEMANAGER SceneManager::GetScenemgr()