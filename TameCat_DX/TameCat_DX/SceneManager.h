#pragma once

#include "stdafx.h"
#include "Singleton.h"


enum SceneNumber
{
	START_SCENENUMBER = 0, SN_STARTSCREEN = 0,
	SN_CATHOME,
	LAST_SCENENUMBER //SceneList배열의 크기 지정이나 반복문 사용 시에만 필요한 것. 해당 번호의 씬은 없다.
	
};

class Scene
{
protected:
	texture* backGround;
	inline void SetBackGround(char* address) { backGround = IMAGEMANAGER->AddImage(address); }

public:
	virtual void Init()=0;
	virtual void Update()=0;
	virtual void Render()=0;
	virtual void Destroy()=0;
};

class SceneManager : public Singleton <SceneManager>
{
private:
	Scene* curScene;
	Scene* sceneList[LAST_SCENENUMBER];

public:
	void Init();
	void Update();
	void Destroy();
	void SetCurrentScene(SceneNumber sn);
	SceneNumber GetCurrentScene();

};

#define SCENEMANAGER SceneManager::GetSingleton()
