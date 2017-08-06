#include "stdafx.h"

SceneManager* SceneManager::GetScenemgr()
{
	if (uniqueSceneMgr == NULL)
	{
		uniqueSceneMgr = new SceneManager;
	}
	return uniqueSceneMgr;
}

void SceneManager::Init()
{
	SceneList[SN_START] = new Scene;
	SceneList[SN_START]->SetBehavior(SN_START);

	SetCurScene(SN_START);
}

void SceneManager::Update()
{
	curScene->Update();
}

void SceneManager::Render()
{
	
}

void SceneManager::Destory()
{
	
}

void SceneManager::SetCurScene(SceneCode sc)
{
	if (0 <= sc&&sc < SN_IMLAST) curScene = SceneList[sc];
}