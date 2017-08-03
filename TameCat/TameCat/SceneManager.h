#pragma once
#include "Scene.h"

enum SceneCode
{
	SC_START=0,
	SC_HOME,
	SC_COLLECTION,
	SC_SHOP,
	SC_MINIGAME,
	SC_INVENTORY,


	SC_IMLAST //1 »« °ªÀÌ ¾ÀÀÇ °¹¼ö
};

class SceneManager
{
private:
	static SceneManager* uniqueSceneMgr;
	Scene* curScene;
	Scene* SceneList[SC_IMLAST - 1];
	SceneManager() {};
public:
	static SceneManager* GetScenemgr();
	void Init();
	void Update();
	void Render();
	void Destory();

	void SetScene();
};

#define SCENEMANAGER SceneManager::GetScenemgr()