#pragma once

#include "stdafx.h"
#include "Singleton.h"


enum SceneNumber
{
	START_SCENENUMBER = 0, SN_STARTSCREEN = 0,
	SN_CATHOME,
	LAST_SCENENUMBER //SceneList�迭�� ũ�� �����̳� �ݺ��� ��� �ÿ��� �ʿ��� ��. �ش� ��ȣ�� ���� ����.
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
