#include "stdafx.h"
#include "CatCollectData.h"

CatCollectData* CatCollectData::uniqueInst = NULL;

CatCollectData::CatCollectData()
{
	for (int i = ONESTARCUT_CAT; i < LAST_CATCODE; i++)
	{
		if (!(i == ONESTARCUT_CAT || TWOSTARCUT_CAT || THREESTARCUT_CAT || LAST_CATCODE));
			collectData[(CatCode)i] = false;
	}
}

CatCollectData* CatCollectData::GetInstance()
{
	if (uniqueInst == NULL)
	{
		uniqueInst = new CatCollectData;
	}
	return uniqueInst;
}

float CatCollectData::GetPercent()
{
	int catCnt = 0, collectCnt = 0;
	float result;
	for (auto it = collectData.begin(); it != collectData.end(); it++)
	{
		catCnt++;
		if (it->second == true) collectCnt++;
	}
	if (collectCnt == 0)
		result = 0.0f;
	else
		result = ((float)collectCnt / catCnt) * 100.0f;

	return result;
}
