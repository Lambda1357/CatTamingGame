#include "stdafx.h"
#include "Toy.h"

Toy::Toy(ItemCode::Toy cd)
{
	switch (cd)
	{
	case ItemCode::Toy::DOLPHINDOLL:
		description.first = "����";
		description.second = "���� ����� �Ϳ��� �����̴�.";
		addLoveP = 10;
		addButlerP = 0;
		break;

	case ItemCode::Toy::RATTOY:
		description.first = "�� ��� �峭��";
		description.second = "�� ����� �ָԸ��� �峭���̴�.";
		addLoveP = 30;
		addButlerP = 1;
		break;

	case ItemCode::Toy::FEATHERROD:
		description.first = "���� ���ô�";
		description.second = "���ô� ���� ������ �޷��־� ��ι̵��� �޷����.";
		addLoveP = 30;
		addButlerP = 2;
		break;

	case ItemCode::Toy::TOWERBALL:
		description.first = "Ÿ�� ��";
		description.second = "���� �����鼭 ��ι̵��� �ű����Ѵ�.";
		addLoveP = 50;
		addButlerP = 0;
		break;

	case ItemCode::Toy::MOBILETOY:
		description.first = "��� ����";
		description.second = "��ι̵��� ����� ���� ġ�� �����Ѵ�.";
		addLoveP = 70;
		addButlerP = 0;
		break;

	case ItemCode::Toy::SCRATCHER:
		description.first = "��ũ����";
		description.second = "��ι̵� ������ �ܱ��ϱ⿡ �ȼ������̴�";
		addLoveP = 100;
		addButlerP = 3;
		break;

	case ItemCode::Toy::CATTOWER:
		description.first = "ĹŸ��";
		description.second = "��ι̵��� �Ƚ�ó�̴�. ������Ѵ�.";
		addLoveP = 120;
		addButlerP = 4;
		break;

	case ItemCode::Toy::CUSHION:
		description.first = "Ĺ�� ���";
		description.second = "��ι̰� �����ϴ� Ĺ���� ���� ����ִ� ����̴�.";
		addLoveP = 150;
		addButlerP = 5;
		break;
	}
	myCode = cd;
}

void Toy::useItem(Cat target)
{
	target.AddButlerP(addButlerP);
	target.AddLove(addLoveP);
	count--;
}

void Toy::RenderInven(HDC dc)
{
	bgBox.SetPos(224 + (70 * ((int)myCode + 1)), 298);
	Object::SetPos(229 + (70 * ((int)myCode + 1)), 303);

	bgBox.Render(dc);
	Object::Render(dc);
}
