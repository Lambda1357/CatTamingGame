#pragma once
#include "stdafx.h"
#include "ItemCode.h"

class Item : public Object
{
protected:
	std::pair<std::string, std::string> description;
	int price;
	int count;

public:
	virtual void UseItem(Cat) = 0;
	virtual void UseItem() = 0;
	virtual void Add(int cnt = 1) { count += cnt; }
	int GetPrice() { return price; }
	int GetCount() { return count; }
	virtual void RenderInven(HDC dc) = 0;

};