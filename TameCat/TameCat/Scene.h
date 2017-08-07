#pragma once

class Scene
{
private:
	Scenebehavior* myScene;
public:
	void Init();
	void Update();
	void Render();
	void Destroy();
	void SetBehavior(SceneCode sCode);
	Scenebehavior* GetBehavior();
};