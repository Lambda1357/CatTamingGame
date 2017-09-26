#pragma once

#include "Singleton.h"
#include "ImageManager.h"

class Scene
{
private:
	texture backGround;

public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Destroy();
};

class SceneManager : public Singleton <SceneManager>
{
private:
	Scene* CurScene;
public:
};

#define SCENEMANAGER SceneManager::GetSingleton()
