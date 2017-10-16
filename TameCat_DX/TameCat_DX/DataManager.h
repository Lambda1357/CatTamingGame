#pragma once
#include "Singleton.h"



class DataManager : public Singleton <DataManager>
{
private:
	int money;
	int heirball;
	enum HouseTheme
	{
		HOUSE,
		FOREST
	};
	HouseTheme current;

};