#include "stdafx.h"
#include "StartScene.h"

void StartScene::Init()
{
	SetBackGround("���� �ּҾ���");
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
