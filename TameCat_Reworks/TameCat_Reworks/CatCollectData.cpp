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
