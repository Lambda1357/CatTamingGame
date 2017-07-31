#include "stdafx.h"
#include "MainGame.h"

void Game::Init(HWND hWnd)
{
	this->hWnd = hWnd;

	GetClientRect(hWnd, &clientBox);
	this->hdc = GetDC(hWnd);

	backdc = CreateCompatibleDC(hdc);
	backbit = CreateCompatibleBitmap(hdc, clientBox.right, clientBox.bottom);
	SelectObject(backdc, backbit);

	imgdc = CreateCompatibleDC(hdc);
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

