#pragma once
class InputManeger
{
private: 
	static InputManeger* UniqueObj;
	POINT mousepos;
	BOOL isClick_cur;
	BOOL isClick_prv;

	BOOL isSpaceDown_cur;
	BOOL isSpaceDown_prv;

	InputManeger();
	~InputManeger();
public:
	static InputManeger* GetUniqueInputMgr();
	void Init();
	void Update();
	void LbuttonDown();
	void LbuttonUp();
	BOOL IsHit(Object);
	BOOL IsHit(RECT);
};



#define INPUTMANEGER InputManeger::GetUniqueInputMgr()
