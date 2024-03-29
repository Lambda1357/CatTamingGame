#include "stdafx.h"
#include "CatCollectData.h"

CatCollectData* CatCollectData::uniqueInst = NULL;

CatCollectData::CatCollectData()
{
	for (int i = ONESTARCUT_CAT; i < LAST_CATCODE; i++)
	{
		if ((i != ONESTARCUT_CAT) && (i != TWOSTARCUT_CAT) && (i != THREESTARCUT_CAT) && (i != LAST_CATCODE))
		{
			collectData[(CatCode)i] = false;
			switch ((CatCode)i)
			{
			case CAT_TAKEALOOK:
				portrait[(CatCode)i].Init(_T("./resource/chara/cat_takealook.bmp"));
				break;
			case CAT_STRIPE:
				portrait[(CatCode)i].Init(_T("./resource/chara/cat_stripe.bmp"));
				break;
			case CAT_SIAMESE:
				portrait[(CatCode)i].Init(_T("./resource/chara/cat_siamese.bmp"));
				break;
			case CAT_PERSIAN:
				portrait[(CatCode)i].Init(_T("./resource/chara/cat_persian.bmp"));
				break;
			case CAT_RUSSIANBLUE:
				portrait[(CatCode)i].Init(_T("./resource/chara/cat_russianblue.bmp"));
				break;
			case CAT_TURKISHANGORA:
				portrait[(CatCode)i].Init(_T("./resource/chara/cat_turkishangora.bmp"));
				break;
			case CAT_SCOTFOLD:
				portrait[(CatCode)i].Init(_T("./resource/chara/cat_scotfold.bmp"));
				break;
			case CAT_SPHYNX:
				portrait[(CatCode)i].Init(_T("./resource/chara/cat_sphynx.bmp"));
				break;
			case CAT_RIBBON:
				portrait[(CatCode)i].Init(_T("./resource/chara/cat_ribbon.bmp"));
				break;
			case CAT_ODDEYE:
				portrait[(CatCode)i].Init(_T("./resource/chara/cat_oddeye.bmp"));
				break;
			case CAT_RABBITHOOD:
				portrait[(CatCode)i].Init(_T("./resource/chara/cat_rabbithood.bmp"));
				break;
			case CAT_FAT:
				portrait[(CatCode)i].Init(_T("./resource/chara/cat_fat.bmp"));
				break;
			case CAT_FLOWER:
				portrait[(CatCode)i].Init(_T("./resource/chara/cat_flower.bmp"));
				break;
			case CAT_RAINBOW:
				portrait[(CatCode)i].Init(_T("./resource/chara/cat_rainbow.bmp"));
				break;
			case CAT_HEROS:
				portrait[(CatCode)i].Init(_T("./resource/chara/cat_heros.bmp"));
				break;
			}
			portrait[(CatCode)i].SetSize(300, 70);
		}
	}
	UnknownPortrait.Init(_T("./resource/chara/cat_unknown.bmp"));
	bgBox.Init(_T("./resource/item/bgBox.bmp"));
	bgBox.SetSize(70, 70);
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

void CatCollectData::Render(HDC hdc)
{
	for (int i = ONESTARCUT_CAT; i < LAST_CATCODE; i++)
	{
		if ((i != ONESTARCUT_CAT) && (i != TWOSTARCUT_CAT) && (i != THREESTARCUT_CAT) && (i != LAST_CATCODE))
		{
			if (i < TWOSTARCUT_CAT)
			{
				if(collectData[(CatCode)i]==true) portrait[(CatCode)i].Render(hdc, 204 + (95 * (i - 1)), 175, 70, 70, 0, 0, 70, 70);
				else UnknownPortrait.Render(hdc, 204 + (95 * (i - 1)), 175, 70, 70, 0, 0, 70, 70);
			}
			else if (i < THREESTARCUT_CAT)
			{
				if (collectData[(CatCode)i] == true) portrait[(CatCode)i].Render(hdc, 204 + (95 * (i - (TWOSTARCUT_CAT + 1))), 315, 70, 70, 0, 0, 70, 70);
				else UnknownPortrait.Render(hdc, 204 + (95 * (i - (TWOSTARCUT_CAT + 1))), 315, 70, 70, 0, 0, 70, 70);
			}
			else if (i < LAST_CATCODE)
			{
				if (collectData[(CatCode)i] == true) portrait[(CatCode)i].Render(hdc, 204 + (95 * (i - (THREESTARCUT_CAT + 1))), 455, 70, 70, 0, 0, 70, 70);
				else UnknownPortrait.Render(hdc, 204 + (95 * (i - (THREESTARCUT_CAT + 1))), 455, 70, 70, 0, 0, 70, 70);
			}
		}
	}
}
