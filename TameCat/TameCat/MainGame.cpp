#include "MainGame.h"

void Game::init(HWND hWnd)
{
	this->hWnd = hWnd;
	this->hdc = GetDC(hWnd);
}

void Game::Update()
{
}

void Game::Render()
{
}

void Game::Destroy()
{
	ReleaseDC(this->hWnd, this->hdc);
}
