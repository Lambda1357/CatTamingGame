#pragma once
#include "Item.h"

class Toy : public Item
{
private:
	ItemCode::Toy myCode;
	int addLoveP, addButlerP;
	void useItem() {};
	Toy();

public:
	Toy(ItemCode::Toy cd);
	void useItem(Cat target);
};