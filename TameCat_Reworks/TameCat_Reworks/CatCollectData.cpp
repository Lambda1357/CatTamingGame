#include "stdafx.h"
#include "CatCollectData.h"

CatCollectData* CatCollectData::uniqueInst = NULL;

CatCollectData::CatCollectData()
{
	for (int i = ONESTARCUT_CAT; i < LAST_CATCODE; i++) collectData[(CatCode)i] = false;
}

CatCollectData* CatCollectData::GetInstance()
{
	if (uniqueInst == NULL)
	{
		uniqueInst = new CatCollectData;
	}
	return uniqueInst;
}
