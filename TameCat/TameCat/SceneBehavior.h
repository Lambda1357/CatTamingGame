#pragma once

class Scenebehavior abstract
{
public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Destory() = 0;
};

class StartScene : public Scenebehavior
{
public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Destroy();
private:
	int sceneStatus;

};