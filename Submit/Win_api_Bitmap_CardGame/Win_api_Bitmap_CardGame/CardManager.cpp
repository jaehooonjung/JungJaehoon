#include "CardManager.h"

CardManager*CardManager::m_hThis = NULL;

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


void CardManager::CardListSet(HWND hWnd, HINSTANCE hInst, bool&gamestatus)
{
	if (gamestatus == true)
		return;
	else
		gamestatus = true;

	HDC hdc = GetDC(hWnd);
	int start_x_tmp = CARDPOSITIONDEFAULT_X, start_y_tmp = CARDPOSITIONDEFAULT_Y;
	int RandomTmp;
	for (int i = 1; i <= (CARDMAX*2); i++, start_x_tmp+= CARDPOSITIONDEFAULT_INTERVAL)
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
			start_y_tmp += Tmp->SizeYOutput() + CARDPOSITIONDEFAULT_INTERVAL*2;
			start_x_tmp = CARDPOSITIONDEFAULT_X-150;
		}
	}

	m_CardBack = new Card;
	m_CardBack->init(hdc, hInst, IDB_BITMAP11);

	ReleaseDC(hWnd, hdc);
}

void CardManager::CardDrawAll(HDC hdc)
{
	for (auto iter = m_CardList.begin(); iter != m_CardList.end(); iter++)
	{
	if ((*iter)->OpenFlagOutput() == false)
		{
			m_CardBack->CardInfoSet((*iter)->CardPosition_x_Output(), (*iter)->CardPosition_y_Output());
			m_CardBack->CardDraw(hdc);
		}
		else
			(*iter)->CardDraw(hdc);
	}
}

void CardManager::CardOpen(int mouse_x, int mouse_y)
{
	for (auto iter = m_CardList.begin(); iter != m_CardList.end(); iter++)
	{
		if (((*iter)->CardPosition_x_Output() <= mouse_x) && (((*iter)->CardPosition_x_Output() + 150) >= mouse_x) && ((*iter)->CardPosition_y_Output() <= mouse_y) && ((*iter)->CardPosition_y_Output() + 250 >= mouse_y))
		{
			(*iter)->CardOpenFlagChange();
			return;
		}
	}

}

CardManager::~CardManager()
{
}