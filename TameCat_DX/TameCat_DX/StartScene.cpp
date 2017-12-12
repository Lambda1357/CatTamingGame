#include "stdafx.h"
#include "StartScene.h"

void StartScene::Init()
{
	SetBackGround("아직 주소없음");
	howtoPlay = NULL;
	buttonList.push_back(new SceneChangeButton(SN_CATHOME));
	buttonList.push_back(new HowtoButton);
	for (auto iter = buttonList.begin(); iter != buttonList.end(); iter++)
	{
		(*iter)->Init();
	}
}

void StartScene::Update()
{
}

void StartScene::Render()
{
}

void StartScene::Destroy()
{
}
