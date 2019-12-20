#include "CardGame.h"



CardGame::CardGame()
{
}

void CardGame::GameInit()
{
	/*
	int m_iStart_x;
	int m_iStart_y;
	bool m_bOpenFlag;
	bool m_bClearFlag;
	Card AreaCrad;
	*/
	int start_x_tmp,start_y_tmp;



	for (int i = 1; i <= (CARDMAX*2); i++)
	{
		Area*Tmp = new Area;
		


		AreaList.push_back(Tmp);
	}
}

CardGame::~CardGame()
{
}
