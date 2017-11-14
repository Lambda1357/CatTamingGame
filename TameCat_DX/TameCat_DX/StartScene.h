#pragma once

#include "stdafx.h"

class StartScene : public Scene
{
public:
	void Init();
	void Update();
	void Render();
	void Destroy();

private:
	Window* howtoPlay;
	std::vector<Button*> buttonList;

};
