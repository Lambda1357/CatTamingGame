#pragma once
#include "stdafx.h"
#include "ItemCode.h"

class Item : protected Object
{
protected:
	std::pair<std::string, std::string> description;
	int price;
	int count = 0;

	static Object bgBox;

public:
	virtual void UseItem(Cat) = 0;
	virtual void UseItem() = 0;
	virtual void Add(int cnt = 1) { count += cnt; }
	virtual void RenderInven(HDC dc) = 0;
	virtual void Init(TCHAR* addr) 
	{ 
		Object::Init(addr);
		Object::SetSize(50, 50);
	}
	static void BgBoxInit(TCHAR* addr);

	int GetPrice() { return price; }
	int GetCount();

};