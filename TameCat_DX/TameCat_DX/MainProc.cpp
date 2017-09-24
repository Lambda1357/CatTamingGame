#include "stdafx.h"


MainProc::MainProc()
{
}


MainProc::~MainProc()
{
}


int MainProc::Init()
{
	bAct = true;

	example = IMAGEMANAGER->AddImage("Texture/example.png");

	return 0;
}


int MainProc::Update()
{

	return 0;
}


int MainProc::Render()
{
	IMAGEMANAGER->Begin();

	IMAGEMANAGER->DrawImage(example, 500, 400, 0.0f, 255);

	IMAGEMANAGER->End();
	return 0;
}


int MainProc::Release()
{
	bAct = false;

	example->lpd3dTex->Release();
	SAFE_DELETE(example);

	PostQuitMessage(0);
	ImageManager::ReleaseSingleton();
	return 0;
}


// Get

BOOL MainProc::GetAct()
{
	return bAct;
}