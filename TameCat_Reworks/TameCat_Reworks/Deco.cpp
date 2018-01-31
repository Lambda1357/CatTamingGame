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
		description.first = "Ȩ �׸�: ����";
		description.second = "Ȩ�� ����� �������� �ٲ� �� �ְ� �ȴ�.";
		break;
	case ItemCode::Deco::THEMEFOREST:
		description.first = "Ȩ �׸�: ��";
		description.second = "Ȩ�� ����� ������ �ٲ� �� �ְ� �ȴ�.";
		break;
	case ItemCode::Deco::THEMEHOME:
		description.first = "Ȩ �׸�: ��";
		description.second = "Ȩ�� ����� ������ �ٲ� �� �ְ� �ȴ�.";
		break;
	}
	myCode = cd;
	count = 1;
}

void Deco::RenderInven(HDC dc)
{
	bgBox.SetPos(224 + (70 * ((int)myCode)), 376);
	Object::SetPos(229 + (70 * ((int)myCode)), 381);

	bgBox.Render(dc);
	Object::Render(dc);
}
