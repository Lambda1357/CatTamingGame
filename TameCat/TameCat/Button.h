#pragma once


class Button : private Object
{
private:
	Buttonbehavior* myButton;
	Scene* PerentScene;
public:
	void Init(Scene* callScene);
	void Update();
	void Render();
	void Destroy();
};