#pragma once
#include "ItemCode.h"

enum SceneNumber
{
	SN_START,
	SN_HOME,
	SN_COLLECTION,
	SN_SHOP,
	SN_MINIGAME,

	LAST_SN //1 –u °ªÀÌ ¾ÀÀÇ ÃÑ °¹¼ö
};

class SceneManeger
{
public:
	static SceneManeger* GetUniqueScenemgr();
	SceneNumber GetScene();
	void SetScene(SceneNumber sn);
	int GetStatus();
	void SetStatus(int sceneStatus);
	void Destroy();
	ItemCode::Deco GetCurTheme() { return currentTheme; }
	void SetThemeTo(ItemCode::Deco code) { currentTheme = code; }

private:
	static SceneManeger* UniqueObj;
	SceneNumber curentScene;
	int curSceneStatus;
	ItemCode::Deco currentTheme;
	SceneManeger();
	virtual ~SceneManeger();
};



#define SCENEMANEGER SceneManeger::GetUniqueScenemgr()