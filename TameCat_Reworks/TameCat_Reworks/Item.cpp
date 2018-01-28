#include "stdafx.h"
#include "Item.h"

void Item::BgBoxInit(TCHAR * addr)
{
	bgBox.Init(addr);
	bgBox.SetSize(60, 60);
}
Object Item::bgBox = Object();