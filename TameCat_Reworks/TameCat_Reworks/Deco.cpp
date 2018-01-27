#include "stdafx.h"
#include "Deco.h"

void Deco::UseItem()
{
	SCENEMANEGER->SetThemeTo(myCode);
}

Deco::Deco(ItemCode::Deco cd)
{
	switch (cd)
	{
	case ItemCode::Deco::THEMEPARK:
		description.first = "홈 테마: 공원";
		description.second = "홈의 배경을 공원으로 바꿀 수 있게 된다.";
		break;
	case ItemCode::Deco::THEMEFOREST:
		description.first = "홈 테마: 숲";
		description.second = "홈의 배경을 숲으로 바꿀 수 있게 된다.";
		break;
	case ItemCode::Deco::THEMEHOME:
		description.first = "홈 테마: 집";
		description.second = "홈의 배경을 집으로 바꿀 수 있게 된다.";
		break;
	}
	myCode = cd;
}

void Deco::RenderInven(HDC dc)
{
	bgBox.SetPos(224 + (70 * ((int)myCode + 1)), 376);
	Object::SetPos(229 + (70 * ((int)myCode + 1)), 381);

	bgBox.Render(dc);
	Object::Render(dc);
}
