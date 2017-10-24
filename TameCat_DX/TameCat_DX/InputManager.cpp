#include "stdafx.h"
#include "InputManager.h"

void InputManager::Init()
{
	isClick_cur = false;
	isClick_prv = false;
}

void InputManager::Cilcked()
{
	isClick_cur = true;
}

void InputManager::Update()
{
	isClick_prv = isClick_cur;
	isClick_cur = false;
}

void InputManager::Destroy()
{
}
