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
			start_y_tmp += Tmp->SizeYOutput() + CARDPOSITIONDEFAULT_INTERVAL;
			start_x_tmp = CARDPOSITIONDEFAULT_X -10;
		}
	}

	m_CardBack = new Card;
	m_CardBack->init(hdc, hInst, IDB_BITMAP11);

	ReleaseDC(hWnd, hdc);
}

void CardManager::CardDrawAll(HDC hdc)
{
	if (m_CardList.size() == NULL)
		return;

	for (auto iter = m_CardList.begin(); iter != m_CardList.end(); iter++)
	{
		if ((*iter)->CARDSTATUSOutput() == CARDSTATUS_UNKNOWN)
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
			int a = 2;
			if ((*iter)->CARDSTATUSOutput() == CARDSTATUS_CLEAR)
				return;
			else
			{
				(*iter)->CardStatusChangeToOpen();
				return;
			}
		}
	}

}

bool CardManager::OpenCardCheck(GAMESTATE& gamestate)
{
	int flag = 0;
	Card*SampleCard1 = NULL;
	Card*SampleCard2 = NULL;

	for (auto iter = m_CardList.begin(); iter != m_CardList.end(); iter++)
	{
		if ((*iter)->CARDSTATUSOutput() == CARDSTATUS_OPEN)
		{
			if (flag == 0)
				SampleCard1 = (*iter);
			else
				SampleCard2 = (*iter);
			flag++;
		}
	}
	if (flag == 2)
	{
		if (SampleCard1->BitmapNameOutput() != SampleCard2->BitmapNameOutput())
		{
			SampleCard1->CardStatusChangeToUnknown();
			SampleCard2->CardStatusChangeToUnknown();
			gamestate = GAMESTATE_PAUSE;
			return true;
		}
		else
		{
			SampleCard1->CardStatusChangeToClear();
			SampleCard2->CardStatusChangeToClear();
			return false;
		}
	}
	else
		return false;
}


CardManager::~CardManager()
{
}
