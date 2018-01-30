#include "stdafx.h"
#include "Item.h"

void Item::BgBoxInit(TCHAR * addr)
{
	bgBox.Init(addr);
	bgBox.SetSize(60, 60);
}
int Item::GetCount()
{
	if (count < 99)
		return count;
	else
		return -1;
}

Object Item::bgBox = Object();