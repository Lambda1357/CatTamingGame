#pragma once
#include "stdafx.h"

//UI Ʋ

class Button
{
	class ButtonBehavior;
	friend class ButtonBehavior;
private:
	POINT myPos;
	texture box;
	class ButtonBehavior
	{
	public:
		virtual void OnCilck();
	};
	ButtonBehavior myBehavior;
public:
	void Init();
	void Update();
	void Render();
	void Destroy();
};

class Window
{
private:
	texture box;
	POINT myPos;

public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Destroy();

};

//UI ����


//���������� ���Ǵ� UI

class SmallCashBar
{
private:
	int parameter;
	texture box;
	POINT myPos;

public:
	void Init();
	void Update();
	void Render();
	void Destroy();
};

