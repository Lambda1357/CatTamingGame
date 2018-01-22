#include "stdafx.h"
#include "Feed.h"

Feed::Feed(ItemCode::Feed cd)
{
	switch (cd)
	{
	case ItemCode::Feed::MILK:
		description.first = "���� ����";
		description.second = "��ι̰� ��ȭ�ϱ� ������ ������� �����̴�.";
		addVelue = 20;
		break;

	case ItemCode::Feed::FEED:
		description.first = "���� ���";
		description.second = "��ι̰� ��θ��� ���� �� �ִ� ����̴�.";
		addVelue = 30;
		break;

	case ItemCode::Feed::CAN:
		description.first = "���� ������";
		description.second = "��ι̰� �����ϴ� ��ġ�� �������̴�.";
		addVelue = 50;
		break;

	case ItemCode::Feed::SUSHI:
		description.first = "���� �����";
		description.second = "��ι��� �ǰ��� å������ Ư�� �丮!";
		addVelue = 75;
		break;

	case ItemCode::Feed::CHUR:
		description.first = "��";
		description.second = "������ �þƵ� ��ι̰� ȯ���ϴ� �α� �����̴�";
		addVelue = 100;
		break;
	}
}

void Feed::UseItem(Cat target)
{
	target.AddHunger(addVelue);
	count--;
}