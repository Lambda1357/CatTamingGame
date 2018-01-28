#pragma once
#include "Item.h"

class Toy : public Item
{
private:
	ItemCode::Toy myCode;
	int addLoveP, addButlerP;
	void UseItem() {};
	Toy();

public:
	Toy(ItemCode::Toy cd);
	void UseItem(Cat target);
	void RenderInven(HDC dc);
};