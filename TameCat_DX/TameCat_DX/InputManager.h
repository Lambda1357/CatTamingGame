#pragma once
#include "stdafx.h"

class InputManager : public Singleton<InputManager>
{
private:
	bool isClick_cur;
	bool isClick_prv;
	POINT mouseCoord;
public:
	void Init();
	void Cilcked();
	void Update();
	void Destroy();
};