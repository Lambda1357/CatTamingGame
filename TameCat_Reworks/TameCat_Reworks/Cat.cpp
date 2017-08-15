#include "stdafx.h"
#include "Cat.h"


void Cat::Init(TCHAR * imgRoot, CatCode m_catCode)
{
	Object::Init(imgRoot);
	int randPositX = rand() % (CATALLOWBOX.right - CATALLOWBOX.left) + CATALLOWBOX.left;
	int randPositY = rand() % (CATALLOWBOX.bottom - CATALLOWBOX.top) + CATALLOWBOX.top;
	RECT catPosit = { randPositX,randPositY,randPositX + CATSIZE_X,randPositY + CATSIZE_Y };
	
	SetPos(catPosit);

	myCatCode = m_catCode;
	
	butlerPoint = 0;
	hungerPoint = 50;
	if (THREESTARCUT_CAT < myCatCode) maxlove = 300;
	else if (TWOSTARCUT_CAT < myCatCode) maxlove = 250;
	else maxlove = 200;

	xSideUp = rand() % 1;
	ySideUp = rand() % 1;
	switch (myCatCode)
	{
	case CAT_TAKEALOOK:
		_tcscpy(catName, TEXT("������ �����"));
		break;
	case CAT_STRIPE:
		_tcscpy(catName, TEXT("�ٹ��� �����"));
		break;
	case CAT_SIAMESE:
		_tcscpy(catName, TEXT("�� �����"));
		break;
	case CAT_PERSIAN:
		_tcscpy(catName, TEXT("�丣�þ� �����"));
		break;
	case CAT_RUSSIANBLUE:
		_tcscpy(catName, TEXT("���þȺ�� �����"));
		break;
	case CAT_TURKISHANGORA:
		_tcscpy(catName, TEXT("��Ű�� �Ӱ�� �����"));
		break;
	case CAT_SCOTFOLD:
		_tcscpy(catName, TEXT("����Ƽ�� ���� �����"));
		break;
	case CAT_SPHYNX:
		_tcscpy(catName, TEXT("����ũ�� �����"));
		break;
	case CAT_RIBBON:
		_tcscpy(catName, TEXT("���� �޸� �����"));
		break;
	case CAT_ODDEYE:
		_tcscpy(catName, TEXT("������� �����"));
		break;
	case CAT_RABBITHOOD:
		_tcscpy(catName, TEXT("�䳢 ��� �����"));
		break;
	case CAT_FAT:
		_tcscpy(catName, TEXT("�׶��� �����"));
		break;
	case CAT_FLOWER:
		_tcscpy(catName, TEXT("�ɴٹ� �����"));
		break;
	case CAT_RAINBOW:
		_tcscpy(catName, TEXT("������ �����"));
		break;
	case CAT_HEROS:
		_tcscpy(catName, TEXT("�ð� �����"));
		break;
	default:
		_tcscpy(catName, TEXT("�̸�����! �����ּ���"));
		break;
	}
}

void Cat::Update()
{
	if (CATALLOWBOX.left >= this->posX) xSideUp = TRUE;
	else if (CATALLOWBOX.right <= this->posX) xSideUp = FALSE;

	if (CATALLOWBOX.top >= this->posY) ySideUp = TRUE;
	else if (CATALLOWBOX.bottom <= this->posY) ySideUp = FALSE;

	if (xSideUp) posX += 3;
	else posX -= 3;

	if (ySideUp) posY += 3;
	else posY -= 3;
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
