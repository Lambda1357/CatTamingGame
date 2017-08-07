#include "stdafx.h"

void Button::Init(Scene* callScene)
{
	ownerScene = callScene;
}

void Button::Update()
{
	if (INPUTMANEGER->ObjHit)
		myButton->ClickAct();
}
