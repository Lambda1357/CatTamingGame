#pragma once
#include "stdafx.h"

class Button
{
private:
	POINT myPos;
	texture box;
	virtual void OnClick();
public:
	void Init();
	void Update();
	void Render();
	void Destroy();
};

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