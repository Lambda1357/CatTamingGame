#include "stdafx.h"
#include "Scenes.h"

void SceneManager::Init()
{
	//�� ��ü�� �ʱ�ȭ�ϴ� ����
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
