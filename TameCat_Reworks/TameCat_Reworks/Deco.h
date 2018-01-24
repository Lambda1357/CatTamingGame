#pragma once
#include "Item.h"

class Deco : public Item
{
private:
	ItemCode::Deco myCode;
	void UseItem(Cat) {};

public:
	void UseItem();
};