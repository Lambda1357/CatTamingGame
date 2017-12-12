#include "stdafx.h"
#include "Scenes.h"

void SceneManager::Init()
{
	//씬 전체를 초기화하는 과정
	for (int index = START_SCENENUMBER; index < LAST_SCENENUMBER; index++)
	{
		switch (index)
		{
		case SN_STARTSCREEN:
			sceneList[SN_STARTSCREEN] = new StartScene;
			break;
		case SN_CATHOME:
			break;
		default:
			break;
		}
	}
}
