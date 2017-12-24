#include "stdafx.h"
#include "Scene.h"

void Scene::BackgroundInit(char* imgAdr)
{
	if (!(background = SDL_LoadBMP(imgAdr)))
		printf("%s Load Failed! please chack file address\n",imgAdr);
}

void Scene::BackgroundFree()
{
	SDL_FreeSurface(background);
}
