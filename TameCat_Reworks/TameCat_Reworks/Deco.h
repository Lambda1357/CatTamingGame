#pragma once
#include "Item.h"

class Deco : public Item
{
private:
	ItemCode::Deco myCode;
	void UseItem(Cat*) {};
	Deco();

public:
	void UseItem();
	Deco(ItemCode::Deco cd);
	void RenderInven(HDC dc);
};