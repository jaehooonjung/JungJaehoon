#pragma once
#include "Card.h"
#include<vector>
#define CARDMAX 10
#define CARDPOSITIONDEFAULT_X 50
#define CARDPOSITIONDEFAULT_Y 10
#define CARDPOSITIONDEFAULT_INTERVAL 150

class CardManager
{
private:
	vector<Card*>m_CardList;
	Card*m_CardBack;
public:
	bool RandomCardOveralpCheck(int bitmapname);
	void CardListSet(HWND hWnd, HINSTANCE hInst, bool&gamestatus);
	void CardDrawAll(HDC hdc);
	void CardOpen(int mouse_x,int mouse_y, int &openflag);
	void CardClearCheck(int &openflag);
	CardManager();
	~CardManager();
};

