#pragma once
#include"Singleton.h"

class Scene
{
private:

public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Destroy();
};

class SceneManager : Singleton <SceneManager>
{
private:

public:
};

#define SCENEMANAGER SceneManager
