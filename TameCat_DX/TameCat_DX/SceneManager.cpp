#include "stdafx.h"
#include "Scenes.h"

void SceneManager::Init()
{
	//씬 전체를 초기화하는 과정
	for (SceneNumber index = START_SCENENUMBER; index < LAST_SCENENUMBER; index++)
	{
		switch (index)
		{
		case SN_STARTSCREEN:
			break;
		case SN_CATHOME:
			break;
		default:
			break;
		}
	}
}
