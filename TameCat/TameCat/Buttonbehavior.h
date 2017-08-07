#pragma once

class Buttonbehavior
{
public:
	virtual void ClickAct() = 0;
	Scene* ownerScene;
};

//SN_START���� SN_HOME���� �̵�����ϴ� ��ư
class StartButton : Buttonbehavior
{
public:
	virtual void ClickAct();
};

//SN_START�� ���¸� ������� ���ӹ���� ���̴� ��ư
class HowtoButton : Buttonbehavior
{
public:
	virtual void ClickAct();
};