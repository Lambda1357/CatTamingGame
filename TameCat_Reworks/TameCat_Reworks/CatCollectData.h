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
	Object bgBox;

	CatCollectData();
public:
	static CatCollectData* GetInstance();
	void CollectCat(CatCode cd) { collectData[cd] = true; }
	bool IsCollected(CatCode cd) { return collectData[cd]; }
	float GetPercent();
	void Render(HDC hdc);
	void Render(HDC hdc, CatCode cd);
};

#define CATCOLLECTDATA CatCollectData::GetInstance()