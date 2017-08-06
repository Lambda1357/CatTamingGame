#include "stdafx.h"

void Scene::SetBehavior(SceneCode sCode)
{
	switch (sCode)
	{
	case SN_START:
		myScene = new StartScene;
		break;
	}
}
