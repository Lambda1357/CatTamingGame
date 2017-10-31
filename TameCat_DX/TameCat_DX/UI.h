#pragma once
#include "stdafx.h"

//UI 틀

class Button
{
	class ButtonBehavior;
	friend class ButtonBehavior;
protected:
	class ButtonBehavior
	{
	public:
		virtual void OnCilck();
	};

	POINT myPos;
	texture box;
	ButtonBehavior* myButton;
	
public:
	void Init();
	void Update();
	void Render();
	void Destroy();
};

class Window
{
protected:
	texture box;
	POINT myPos;
	
public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Destroy();

};

//UI 구현
// 버튼
class SceneChangeButton : public Button
{
private:
	SceneNumber Parameter; //버튼을 눌렀을 때 이동할 씬
public:
	inline SceneChangeButton(SceneNumber sn) { Parameter = sn; }
	void Init();
	void Update();
	void Render();
	void Destroy();
};


// 윈도우
class InventoryWindow : public Window
{
	
};

class InventoryButton : public Button
{
	
};


//독립적으로 사용되는 UI

class SmallCashBar
{
protected:
	int parameter;
	texture box;
	POINT myPos;

public:
	void Init();
	void Update();
	void Render();
	void Destroy();
};

