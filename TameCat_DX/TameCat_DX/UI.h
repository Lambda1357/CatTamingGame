#pragma once
#include "stdafx.h"

//Ʋ ����

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
	void ImageInit(char* addr);

public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Destroy();

};

//���� ����

class SceneChangeButton : public Button
{
private:
	SceneNumber parameter; //��ư�� ������ �� �̵��� ��
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

class HowToWindow : public Window
{
private:
	std::string description;

public:
	void Init();
	void Update();
	void Render();
	void Destroy();

};

class HowtoButton : public Button
{
private:
	
public:
	void Init();
	void Update();
	void Render();
	void Destroy();
};


//	���������� ���Ǵ� UI

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

