#include "stdafx.h"
#include "Feed.h"

Feed::Feed(ItemCode::Feed cd)
{
	switch (cd)
	{
	case ItemCode::Feed::MILK:
		description.first = "냥이 우유";
		description.second = "고먐미가 소화하기 좋도록 만들어진 우유이다.";
		addVelue = 20;
		break;

	case ItemCode::Feed::FEED:
		description.first = "냥이 사료";
		description.second = "고먐미가 배부르게 먹을 수 있는 사료이다.";
		addVelue = 30;
		break;

	case ItemCode::Feed::CAN:
		description.first = "냥이 통조림";
		description.second = "고먐미가 좋아하는 참치맛 통조림이다.";
		addVelue = 50;
		break;

	case ItemCode::Feed::SUSHI:
		description.first = "냥이 보양식";
		description.second = "고먐미의 건강을 책임지는 특제 요리!";
		addVelue = 75;
		break;

	case ItemCode::Feed::CHUR:
		description.first = "츄르";
		description.second = "냄새만 맡아도 고먐미가 환장하는 인기 간식이다";
		addVelue = 100;
		break;
	}
	myCode = cd;
	count = 1;
}

void Feed::UseItem(Cat* target)
{
	target->AddHunger(addVelue);
	count--;
}

void Feed::RenderInven(HDC dc)
{
	bgBox.SetPos(224 + (70 * ((int)myCode)), 215 );
	Object::SetPos(229 + (70 * ((int)myCode)), 220 );

	bgBox.Render(dc);
	Object::Render(dc);
}
