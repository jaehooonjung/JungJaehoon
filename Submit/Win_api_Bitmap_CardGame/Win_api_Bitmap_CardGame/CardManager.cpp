#include "CardManager.h"



CardManager::CardManager()
{
}

void CardManager::Init(HWND hWnd, HINSTANCE hInst) //삭제해야함
{
	HDC hdc = GetDC(hWnd);

	m_dog.init(hdc, hInst, IDB_BITMAP1);
	m_tiger.init(hdc, hInst, IDB_BITMAP2);
	m_duck.init(hdc, hInst, IDB_BITMAP3);
	m_elephant.init(hdc, hInst, IDB_BITMAP4);
	m_cow.init(hdc, hInst, IDB_BITMAP5);
	m_horse.init(hdc, hInst, IDB_BITMAP6);
	m_cat.init(hdc, hInst, IDB_BITMAP7);
	m_monkey.init(hdc, hInst, IDB_BITMAP8);
	m_frog.init(hdc, hInst, IDB_BITMAP9);
	m_chicken.init(hdc, hInst, IDB_BITMAP10);
	m_black.init(hdc, hInst, IDB_BITMAP11);

	ReleaseDC(hWnd, hdc);
}

void CardManager::OutputRandomCard()
{
	/*
	랜덤으로 1~10 까지 숫자를 뽑고 
	전체 백터에서 같은 숫자가 2개 이상되면 반복문을 새로 돌린다
	아니라면 Card의 인이트 함수를 쓰낟
	
	
	*/
}


void CardManager::CardListSet()
{
	int start_x_tmp = 10, start_y_tmp = 10;
	
	for (int i = 1; i <= (CARDMAX*2); i++)
	{
		Card * Tmp = new Card;


		Tmp->CardInfoSet(start_x_tmp, start_y_tmp);
		CardList.push_back(Tmp);
		start_x_tmp += Tmp->SizeXOutput();
		if (i == 10)
			start_y_tmp += Tmp->SizeYOutput();
	}
}

void CardManager::CardDrawAll()
{
	for (auto iter = CardList.begin(); iter != CardList.end(); iter++)
	{



	}
}

CardManager::~CardManager()
{
}
