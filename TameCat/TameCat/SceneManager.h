#pragma once
#include "Scene.h"
class SceneManager
{
private:
	Scene sceneList[5];
public:
	void Init();
	void Update();
	void Render();
	void Destroy();

	void SetScene();
};