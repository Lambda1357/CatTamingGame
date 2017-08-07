#pragma once
#include "stdafx.h"

class Button : private Object
{
private:
	Buttonbehavior* myButton;
	Scene* ownerScene;
public:
	void Init(Scene* callScene);
	void Update();
	void Render();
	void Destroy();
};