#include "stdafx.h"
#include "Toy.h"

Toy::Toy(ItemCode::Toy cd)
{
	switch (cd)
	{
	case ItemCode::Toy::DOLPHINDOLL:
		description.first = "인형";
		description.second = "돌고래 모양의 귀여운 인형이다.";
		addLoveP = 10;
		addButlerP = 0;
		break;

	case ItemCode::Toy::RATTOY:
		description.first = "쥐 모양 장난감";
		description.second = "쥐 모양의 주먹만한 장난감이다.";
		addLoveP = 30;
		addButlerP = 1;
		break;

	case ItemCode::Toy::FEATHERROD:
		description.first = "깃털 낚시대";
		description.second = "낚시대 끝에 깃털이 달려있어 고먐미들이 달려든다.";
		addLoveP = 30;
		addButlerP = 2;
		break;

	case ItemCode::Toy::TOWERBALL:
		description.first = "타워 볼";
		description.second = "공을 굴리면서 고먐미들이 신기해한다.";
		addLoveP = 50;
		addButlerP = 0;
		break;

	case ItemCode::Toy::MOBILETOY:
		description.first = "모빌 토이";
		description.second = "고먐미들이 모빌을 툭툭 치며 좋아한다.";
		addLoveP = 70;
		addButlerP = 0;
		break;

	case ItemCode::Toy::SCRATCHER:
		description.first = "스크래쳐";
		description.second = "고먐미들 발톱을 긁긁하기에 안성맞춤이다";
		addLoveP = 100;
		addButlerP = 3;
		break;

	case ItemCode::Toy::CATTOWER:
		description.first = "캣타워";
		description.second = "고먐미들의 안식처이다. 편안해한다.";
		addLoveP = 120;
		addButlerP = 4;
		break;

	case ItemCode::Toy::CUSHION:
		description.first = "캣닢 쿠션";
		description.second = "고먐미가 좋아하는 캣닢이 가득 들어있는 쿠션이다.";
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
