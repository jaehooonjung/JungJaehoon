#pragma once
#include "Card.h"
#include<vector>
#define CARDMAX 10
#define CARDPOSITIONDEFAULT_X 10
#define CARDPOSITIONDEFAULT_Y 10
#define CARDPOSITIONDEFAULT_INTERVAL 10

enum GAMESTATE
{
	GAMESTATE_GAMEOVER,
	GAMESTATE_PLAYING,
	GAMESTATE_PAUSE
};

class CardManager
{
private:
	vector<Card*>m_CardList;
	Card*m_CardBack;
public:
	bool RandomCardOveralpCheck(int bitmapname);
	void CardListSet(HWND hWnd, HINSTANCE hInst, GAMESTATE& gamestate);
	void CardDrawAll(HDC hdc);
	void CardOpen(int mouse_x, int mouse_y);
	bool OpenCardCheck(GAMESTATE& gamestate);
	CardManager();
	~CardManager();
};

