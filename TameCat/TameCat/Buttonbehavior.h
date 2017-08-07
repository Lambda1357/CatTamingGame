#pragma once

class Buttonbehavior
{
public:
	virtual void ClickAct() = 0;
	Scene* ownerScene;
};

//SN_START에서 SN_HOME으로 이동담당하는 버튼
class StartButton : Buttonbehavior
{
public:
	virtual void ClickAct();
};

//SN_START의 상태를 변경시켜 게임방법을 보이는 버튼
class HowtoButton : Buttonbehavior
{
public:
	virtual void ClickAct();
};