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
	static CardManager* m_hThis;
	vector<Card*>m_CardList;
	Card*m_CardBack;
public:
	static CardManager* GetInstace()
	{
		if (m_hThis == NULL)
			m_hThis = new CardManager;
		return m_hThis;
	}
	bool RandomCardOveralpCheck(int bitmapname);
	void CardListSet(HWND hWnd, HINSTANCE hInst, bool&gamestatus);
	void CardDrawAll(HDC hdc);
	void CardOpen(int mouse_x,int mouse_y);
	CardManager();
	~CardManager();
};

