#pragma once

class Buttonbehavior
{
	virtual void ClickAct() = 0;
};

//SN_START���� SN_HOME���� �̵�����ϴ� ��ư
class StartButton : Buttonbehavior
{
	virtual void ClickAct();
};

//SN_START�� ���¸� ������� ���ӹ���� ���̴� ��ư
class HowtoButton : Buttonbehavior
{
	virtual void ClickAct();
};