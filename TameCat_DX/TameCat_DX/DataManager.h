#pragma once
#include "stdafx.h"

class Cat
{

};

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