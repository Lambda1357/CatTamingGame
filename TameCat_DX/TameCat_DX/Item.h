#pragma once
#include "stdafx.h"

class Item
{
public:
	enum ItemType
	{
		CATFOOD,
		CATTOY,
		HOUSEADDON,
	};
	ItemType Type;
private:
	std::string itemName;
	std::string description;

};