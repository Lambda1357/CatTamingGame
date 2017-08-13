#pragma once
class InputManeger
{
private: 
	static InputManeger* UniqueObj;
	int mousePosX, mousePosY;
	BOOL isClick_cur;
	BOOL isClick_prv;

	BOOL isSpaceDown_cur;
	BOOL isSpaceDown_prv;

	InputManeger();
	~InputManeger();
public:
	static InputManeger* GetUniqueInputMgr();
	void ClickUpdate(UINT msg, WPARAM wParam, LPARAM lParam);
	BOOL IsHit(Object);
};

#define INPUTMANEGER InputManeger::GetUniqueInputMgr()
