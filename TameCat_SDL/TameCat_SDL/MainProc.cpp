#include "stdafx.h"
#include "MainProc.h"
#include "MouseInput.h"
#include "SceneManager.h"

void MainProc::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL video init Failed! SDL_Error : %s\n", SDL_GetError());
	}
	pWindow = SDL_CreateWindow("TameCat", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (pWindow == NULL)
	{
		printf("Window could not be created! SDL_Error: %s", SDL_GetError());
	}
	else
	{
		//Program Init goes here
		SCENEMANAGER->Init();

		pScreen = SDL_GetWindowSurface(pWindow);
	}
}

bool MainProc::Update()
{
	if (!evntHandler.HandleEvent()) return false;

	SCENEMANAGER->Update();

	return true;
}

void MainProc::Render()
{
	SCENEMANAGER->Render(pScreen);
	
	SDL_UpdateWindowSurface(pWindow);
}

void MainProc::Destroy()
{
	SCENEMANAGER->Destroy();
	MOUSEINPUT->ReleaseInstance();
	SDL_FreeSurface(pScreen);
	SDL_DestroyWindow(pWindow);

	SDL_Quit();
}

MainProc::MainProc()
{
	pWindow = NULL;
	pScreen = NULL;
}

MainProc::~MainProc()
{
}
