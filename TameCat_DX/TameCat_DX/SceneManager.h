#pragma once

#include "stdafx.h"
#include "Singleton.h"


enum SceneNumber
{
	START_SCENENUMBER = 0, SN_STARTSCREEN = 0,
	SN_CATHOME,
	LAST_SCENENUMBER //SceneList배열의 크기 지정이나 반복문 사용 시에만 필요한 것. 해당 번호의 씬은 없다.
};

inline static SceneNumber& operator++(SceneNumber& sn) { return sn = SceneNumber(sn + 1); }

class Scene
{
protected:
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
	Scene* curScene;
	Scene sceneList[LAST_SCENENUMBER];
public:
	void Init();
	void Update();
	void Render();
	void Destroy();
};

#define SCENEMANAGER SceneManager::GetSingleton()
