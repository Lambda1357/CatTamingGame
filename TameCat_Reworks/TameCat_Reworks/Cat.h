#pragma once
#define CATSIZE_X 100
#define CATSIZE_Y 75

extern HWND g_Hwnd;

const RECT CATALLOWBOX = { 100,80,880,480 };

enum CatCode
{
	//1¼º
	ONESTARCUT_CAT,

	CAT_TAKEALOOK,
	CAT_STRIPE,
	CAT_SIAMESE,
	CAT_PERSIAN,
	CAT_RUSSIANBLUE,
	CAT_TURKISHANGORA,
	CAT_SCOTFOLD,

	//2¼º
	TWOSTARCUT_CAT,

	CAT_SPHYNX,
	CAT_RIBBON,
	CAT_ODDEYE,
	CAT_RABBITHOOD,
	CAT_FAT,

	//3¼º
	THREESTARCUT_CAT,

	CAT_FLOWER,
	CAT_RAINBOW,
	CAT_HEROS
};

class Cat : Object
{
private:
	CatCode myCatCode;

	int rareStar;
	int butlerPoint;
	int hungerPoint;
	int lovePoint;
	int maxlove;

	BOOL xSideUp;
	BOOL ySideUp;

	TCHAR catName[24];
public:
	virtual void Init(TCHAR* imgRoot, CatCode m_catCode);
	void Update();
	void Destoy();

	void AddHunger(int addCnt);
	void AddLove(int addCnt);

	Cat();
	~Cat();
};

