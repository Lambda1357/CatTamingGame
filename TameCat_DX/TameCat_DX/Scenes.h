#pragma once

#include "stdafx.h"
class StartScene : Scene
{
public:
	void Init();
	void Update();
	void Render();
	void Destroy();
	enum SceneState
	{
		DEFAULT,
		HOWTO
	};
private:
	SceneState currentState;

};
