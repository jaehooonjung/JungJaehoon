#include "CardManager.h"



CardManager::CardManager()
{
	srand((unsigned)time(NULL));
}

bool CardManager::RandomCardOveralpCheck(int bitmapname)
{
	int flag = 0;
	for (auto iter = m_CardList.begin(); iter != m_CardList.end(); iter++)
	{
		if ((*iter)->BitmapNameOutput() == bitmapname)
			flag++;
	}
	if (flag == 2)
		return false;
	else
		return true;
}


void CardManager::CardListSet(HWND hWnd, HINSTANCE hInst, GAMESTATE& gamestate)
{
	if (gamestate != GAMESTATE_GAMEOVER)
		return;
	else
		gamestate = GAMESTATE_PLAYING;

	HDC hdc = GetDC(hWnd);
	int start_x_tmp = CARDPOSITIONDEFAULT_X, start_y_tmp = CARDPOSITIONDEFAULT_Y;
	int RandomTmp;
	for (int i = 1; i <= (CARDMAX * 2); i++, start_x_tmp += CARDPOSITIONDEFAULT_INTERVAL)
	{
		Card * Tmp = new Card;
		do
		{
			RandomTmp = (rand() % 10) + 101;

		} while (RandomCardOveralpCheck(RandomTmp) == false);

		Tmp->init(hdc, hInst, RandomTmp);
		Tmp->CardInfoSet(start_x_tmp, start_y_tmp);
		m_CardList.push_back(Tmp);
		start_x_tmp += Tmp->SizeXOutput();
		if (i == 10)
		{
			start_y_tmp += Tmp->SizeYOutput() + CARDPOSITIONDEFAULT_INTERVAL * 2;
			start_x_tmp = CARDPOSITIONDEFAULT_X - 150;
		}
	}

	m_CardBack = new Card;
	m_CardBack->init(hdc, hInst, IDB_BITMAP11);

	ReleaseDC(hWnd, hdc);
}



CardManager::~CardManager()
{
}
