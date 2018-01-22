#pragma once
#include "Item.h"

class Feed : public Item
{
private:
	ItemCode::Feed myCode;
	int addVelue;
	void UseItem() {};
	Feed();

public:
	Feed(ItemCode::Feed cd);
	void UseItem(Cat target);

};