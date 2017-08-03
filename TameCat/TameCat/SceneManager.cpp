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
	Scene
}

