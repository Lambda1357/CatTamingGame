#pragma once
#include "Object.h"
#include "Buttonbehavior.h"

class Button : private Object
{
private:
	Buttonbehavior* myButton;
	void ClickAct();
public:
	void Init();
	void Update();
	void Render();
	void Destroy();
};