#pragma once
#include "SceneBehavior.h"

class Scene
{
private:
	Scenebehavior* myScene;
public:
	void Init();
	void Update();
	void Render();
	void Destroy();
};