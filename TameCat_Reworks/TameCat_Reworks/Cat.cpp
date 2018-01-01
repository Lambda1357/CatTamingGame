#include "stdafx.h"
#include "Cat.h"


void Cat::Init(TCHAR* imgRoot, CatCode m_catCode)
{
	Object::Init(imgRoot);
	int randPositX = rand() % (CATALLOWBOX.right - CATALLOWBOX.left) + CATALLOWBOX.left;
	int randPositY = rand() % (CATALLOWBOX.bottom - CATALLOWBOX.top) + CATALLOWBOX.top;
	RECT catPosit = { randPositX,randPositY,randPositX + CATSIZE_X,randPositY + CATSIZE_Y };

	SetPos(catPosit);

	myCatCode = m_catCode;

	butlerPoint = 0;
	hungerPoint = 50;
	lovePoint = 50;
	if (THREESTARCUT_CAT < myCatCode) maxlove = 300;
	else if (TWOSTARCUT_CAT < myCatCode) maxlove = 250;
	else maxlove = 200;

	isAddingX = rand() % 1;
	isAddingY = rand() % 1;
	curFrameNum = (rand() % 2) == 0 ? 0 : 2;

	animatingSpeed = 45;

	switch (myCatCode)
	{
	case CAT_TAKEALOOK:
		_tcscpy(catName, TEXT("떼껄룩 고양이"));
		break;
	case CAT_STRIPE:
		_tcscpy(catName, TEXT("줄무늬 고양이"));
		break;
	case CAT_SIAMESE:
		_tcscpy(catName, TEXT("샴 고양이"));
		break;
	case CAT_PERSIAN:
		_tcscpy(catName, TEXT("페르시안 고양이"));
		break;
	case CAT_RUSSIANBLUE:
		_tcscpy(catName, TEXT("러시안블루 고양이"));
		break;
	case CAT_TURKISHANGORA:
		_tcscpy(catName, TEXT("터키쉬 앙고라 고양이"));
		break;
	case CAT_SCOTFOLD:
		_tcscpy(catName, TEXT("스코티쉬 폴드 고양이"));
		break;
	case CAT_SPHYNX:
		_tcscpy(catName, TEXT("스핑크스 고양이"));
		break;
	case CAT_RIBBON:
		_tcscpy(catName, TEXT("리본 달린 고양이"));
		break;
	case CAT_ODDEYE:
		_tcscpy(catName, TEXT("오드아이 고양이"));
		break;
	case CAT_RABBITHOOD:
		_tcscpy(catName, TEXT("토끼 잠옷 고양이"));
		break;
	case CAT_FAT:
		_tcscpy(catName, TEXT("뚱뚱한 고양이"));
		break;
	case CAT_FLOWER:
		_tcscpy(catName, TEXT("꽃다발 고양이"));
		break;
	case CAT_RAINBOW:
		_tcscpy(catName, TEXT("무지개 고양이"));
		break;
	case CAT_HEROS:
		_tcscpy(catName, TEXT("시공 고양이"));
		break;
	default:
		_tcscpy(catName, TEXT("이름오류! 문의주세요"));
		break;
	}
}

void Cat::Update()
{
	static int updateCounter = 1;

	if (CATALLOWBOX.left >= this->posX) isAddingX = TRUE;
	else if (CATALLOWBOX.right <= this->posX) isAddingX = FALSE;

	if (CATALLOWBOX.top >= this->posY) isAddingY = TRUE;
	else if (CATALLOWBOX.bottom <= this->posY) isAddingY = FALSE;

	if (isAddingX) posX += 1;
	else posX -= 1;

	if (isAddingY) posY += 1;
	else posY -= 1;

	if (updateCounter>animatingSpeed)
	{
		switch (curFrameNum)
		{
		case 2: curFrameNum = 0; break;
		case 0: curFrameNum = 2; break;
		default: curFrameNum = 0; break;
		}
		updateCounter = 0;
	}

	updateCounter++;
}

void Cat::Render(HDC hdc)
{
	imgDC = CreateCompatibleDC(hdc);
	oldBitmap = (HBITMAP)SelectObject(imgDC, myBitmap);

	TransparentBlt(hdc, posX - sizeX, posY - sizeY, sizeX * 2, sizeY * 2, imgDC, (sizeX * 2) * curFrameNum, 0, sizeX * 2, sizeY * 2, RGB(255, 0, 255));

	SelectObject(imgDC, oldBitmap);
	DeleteDC(imgDC);
}

void Cat::Destoy()
{
	DeleteObject(myBitmap);
}

void Cat::AddHunger(int addCnt)
{
	if (hungerPoint + addCnt < 100) hungerPoint += addCnt;
	else hungerPoint = 100;
}

void Cat::AddLove(int addCnt)
{
	if (lovePoint + addCnt < 100) lovePoint += addCnt;
	else lovePoint = 100;
}

Cat::Cat()
{
}


Cat::~Cat()
{
}
