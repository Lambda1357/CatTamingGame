#pragma once
#include <iostream>
#include <map>
#include "Cat.h"

class CatCollectData
{
private:
	static CatCollectData* uniqueInst;
	std::map<CatCode, bool> collectData;
	std::map<CatCode, Object> portrait;
	Object UnknownPortrait;

	CatCollectData();
public:
	static CatCollectData* GetInstance();
	void CollectCat(CatCode cd) { collectData[cd] = true; }
	bool IsCollected(CatCode cd) { return collectData[cd]; }
	float GetPercent();
};

#define CATCOLLECTDATA CatCollectData::GetInstance()