#include "stdafx.h"
#include "SceneManeger.h"


SceneManeger* SceneManeger::GetUniqueScenemgr()
{
	if (UniqueObj == NULL) UniqueObj = new SceneManeger;
	return UniqueObj;
}

SceneNumber SceneManeger::GetScene()
{
	return curentScene;
}

void SceneManeger::SetScene(SceneNumber sn)
{
	curSceneStatus = 0;
	curentScene = sn;
}

int SceneManeger::GetStatus()
{
	return curSceneStatus;
}

void SceneManeger::SetStatus(int sceneStatus)
{
	curSceneStatus = sceneStatus;
}

SceneManeger::SceneManeger()
{
}


SceneManeger::~SceneManeger()
{
}
