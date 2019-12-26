#pragma once
#include"Card.h"
#include<vector>
#include"resource.h"
#define CARDMAX 10
#define CARDPOSITIONDEFAULT_X 10
#define CARDPOSITIONDEFAULT_Y 10
#define CARDPOSITIONDEFAULT_INTERVAL 10
class CardManager
{
private:
	static CardManager* m_hThis;
	vector<Card*>m_CardList;
	Card*m_CardBack;
public:
	CardManager();
	void CardListSet(HWND hWnd, HINSTANCE hInst, bool&gamestatus);
	bool RandomCardOveralpCheck(int bitmapname);
	void CardDrawAll(HDC hdc);
	~CardManager();
};

