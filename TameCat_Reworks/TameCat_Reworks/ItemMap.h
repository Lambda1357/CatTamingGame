#pragma once
#include <map>
#include "ItemCode.h"

class Item;

struct ItemMap
{
	std::map<ItemCode::Feed, Item*> feed;
	std::map<ItemCode::Toy, Item*> toy;
	std::map<ItemCode::Deco, Item*> Deco;
};