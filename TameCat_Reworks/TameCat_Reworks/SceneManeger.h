#pragma once
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
private:
	static SceneManeger* UniqueObj;
	SceneNumber curentScene;
	int curSceneStatus;
	SceneManeger();
	virtual ~SceneManeger();
};



#define SCENEMANEGER SceneManeger::GetUniqueScenemgr()