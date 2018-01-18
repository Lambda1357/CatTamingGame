#pragma once
#define CATSIZE_X 100
#define CATSIZE_Y 70

extern HWND g_Hwnd;

const RECT CATALLOWBOX = { 100,155,880,480 };

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

class Cat : public Object
{
private:
	CatCode myCatCode;
	HBITMAP reverseImg;

	int rareStar;
	int butlerPoint;
	int hungerPoint;
	int lovePoint;
	int maxlove;
	short curFrameNum;
	int animatingSpeed;
	int updateCounter;

	BOOL isAddingX;
	BOOL isAddingY;
	BOOL isMoving;

	int movingChkDelay;

public:
	virtual void Init(TCHAR* imgRoot, CatCode m_catCode);
	void Update();
	void Render(HDC hdc);
	void Destoy();
	void PortraitRander(HDC hdc);

	TCHAR catName[24];
	void AddHunger(int addCnt);
	void AddLove(int addCnt);
	inline int Gethunger() { return hungerPoint; };
	inline int GetLove() { return lovePoint; };
	inline int GetMaxLove() { return maxlove; };

	Cat();
	~Cat();
};

