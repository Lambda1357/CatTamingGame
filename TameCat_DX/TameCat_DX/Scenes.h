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
		START
	};
private:
	SceneState currentState;
	Window HowToPlay;
	std::vector<Button> ButtonList;

};
