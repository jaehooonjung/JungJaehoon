#pragma once
#include "Card.h"
#include<vector>
using namespace std;
#define CARDMAX 10

class CardManager
{
private:
	//����
	Card m_dog;
	Card m_tiger;
	Card m_duck;
	Card m_elephant;
	Card m_cow;
	Card m_horse;
	Card m_cat;
	Card m_monkey;
	Card m_frog;
	Card m_chicken;
	Card m_black;
	// �̱��� ����

	vector<Card*>CardList;
public:
	void Init(HWND hWnd, HINSTANCE hInst); //����
	void OutputRandomCard();
	void CardListSet();
	void CardDrawAll();
	CardManager();
	~CardManager();
};

