#include "stdafx.h"
#include "Scenes.h"

void SceneManager::Init()
{
	//�� ��ü�� �ʱ�ȭ�ϴ� ����
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
