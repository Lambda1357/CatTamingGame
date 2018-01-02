#include "stdafx.h"
#include "Cat.h"


void Cat::Init(TCHAR* imgRoot, CatCode m_catCode)
{

	Object::Init(imgRoot);
	TCHAR tmp[256] = { 0 };
	TCHAR add[8] = TEXT("2.bmp");
	_tcsncpy(tmp, imgRoot, _tcslen(imgRoot) - 4);
	TCHAR* tmp2 = _tcscat(tmp, add);

	reverseImg = (HBITMAP)LoadImage(NULL, tmp2, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

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
	isMoving = TRUE;
	movingChkDelay = 0;
	curFrameNum = (rand() % 2) == 0 ? 0 : 2;

	animatingSpeed = 45;
	updateCounter = rand() % 30;

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
	if (isMoving)
	{
		//����� ���α�
		if (CATALLOWBOX.left >= this->posX) isAddingX = TRUE;
		else if (CATALLOWBOX.right <= this->posX) isAddingX = FALSE;

		if (CATALLOWBOX.top >= this->posY) isAddingY = TRUE;
		else if (CATALLOWBOX.bottom <= this->posY) isAddingY = FALSE;

		//����� �̵�
		if (isAddingX) posX += 1;
		else posX -= 1;

		if (isAddingY) posY += 1;
		else posY -= 1;

		//�ִϸ��̼�
		if (updateCounter > animatingSpeed)
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

	if (movingChkDelay < 0)
	{
		{
			int key = rand() % 100;
			if (isMoving) key < 15 ? isMoving = false : NULL;
			else isMoving = true;
		}
		movingChkDelay = (rand()%150)+35;
	}
	movingChkDelay--;
}

void Cat::Render(HDC hdc)
{
	imgDC = CreateCompatibleDC(hdc);
	if (!isAddingX) {
		oldBitmap = (HBITMAP)SelectObject(imgDC, myBitmap);
		TransparentBlt(hdc, posX - sizeX, posY - sizeY, sizeX * 2, sizeY * 2,
			imgDC, (sizeX * 2) * curFrameNum, 0, sizeX * 2, sizeY * 2, RGB(255, 0, 255));
	}
	else
	{
		oldBitmap = (HBITMAP)SelectObject(imgDC, reverseImg);
		TransparentBlt(hdc, posX - sizeX, posY - sizeY, sizeX * 2, sizeY * 2,
			imgDC, (300 - CATSIZE_X) - ((sizeX * 2) * curFrameNum), 0, sizeX * 2, sizeY * 2, RGB(255, 0, 255));
	}


	SelectObject(imgDC, oldBitmap);
	DeleteDC(imgDC);
}

void Cat::Destoy()
{
	DeleteObject(reverseImg);
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
