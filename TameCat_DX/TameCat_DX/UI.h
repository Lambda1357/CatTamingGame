#pragma once
#include "stdafx.h"

//틀 정의

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

//구현 정의

class SceneChangeButton : public Button
{
private:
	SceneNumber parameter; //버튼을 눌렀을 때 이동할 씬
	SceneChangeButton();
	class SceneChangeBehavior : public ButtonBehavior
	{
	private:
		SceneChangeButton* perent;
	public:
		inline SceneChangeBehavior(SceneChangeButton &p) { perent = &p; }
		inline SceneChangeBehavior(SceneChangeButton* p) { perent = p; }
		void OnCilck();
	};
	friend class SceneChangeBehavior;

public:
	inline SceneChangeButton(SceneNumber sn) { parameter = sn; }
	void Init();
	void Update();
	void Render();
	void Destroy();
};

class HowtoButton : public Button
{
	
};


//	독립적으로 사용되는 UI

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

