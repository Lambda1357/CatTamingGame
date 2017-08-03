#pragma once

class Buttonbehavior
{
	virtual void ClickAct() = 0;
};

class StartButton : Buttonbehavior
{
	virtual void ClickAct();
};