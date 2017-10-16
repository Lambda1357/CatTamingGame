#pragma once

#include "stdafx.h"
class StartScene : Scene
{
private:
	enum SceneState
	{
		DEFAULT,
		HOWTO
	};

	SceneState currentState;
public:
	void Init();
	void Update();
	void Render();
	void Destroy();
};
