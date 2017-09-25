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

	return 0;
}


int MainProc::Update()
{

	return 0;
}


int MainProc::Render()
{

	return 0;
}


int MainProc::Release()
{
	bAct = false;

	PostQuitMessage(0);
	ImageManager::ReleaseSingleton();
	return 0;
}


// Get

BOOL MainProc::GetAct()
{
	return bAct;
}