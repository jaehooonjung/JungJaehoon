#include "Minesweeper.h"



Minesweeper::Minesweeper()
{
	
	m_MapDraw.MapSizeSet(WIDTH_DEFUALT, HEIGHT_DEFUALT);
	m_iWidth = WIDTH_DEFUALT;
	m_iHeight = HEIGHT_DEFUALT;
}

void Minesweeper::input()
{
	char ch = getch();
	switch (ch)
	{
	case KEY_LEFT:
	case KEY_RIGHT:
	case KEY_UP:
	case KEY_DOWN:
		m_Player.CursorMove(ch, m_iWidth, m_iHeight);
		
		break;
	case KEY_ESC:
		m_bGameState = false;
		return;
	case KEY_SPACEBAR:
		break;
	}
	Update();
}

void Minesweeper::Update()
{
	m_MapDraw.GameMapDraw(m_iWidth, m_iHeight);
	//맵을 그리고 지뢰가 아닌걸로 판명된 지점을 지운다.
}

void Minesweeper::MinesweeperGameStart()
{
	m_bGameState = true;
	m_MapDraw.GameMapDraw(m_iWidth, m_iHeight);
	MineManager::GetInstace()->MineCreate(m_iWidth, m_iHeight);
	while (m_bGameState)
	{
		m_Player.DrawCursor();
		input();
	}

}

void Minesweeper::MinesweeperMenu()
{
	int Select;

	while (1)
	{
		system("cls");
		m_MapDraw.DrawMidText("===== 지뢰찾기 =====", m_iWidth, m_iHeight*0.3f);
		m_MapDraw.DrawMidText("1. 게임시작", m_iWidth, m_iHeight*0.4f);
		m_MapDraw.DrawMidText("2. 종료", m_iWidth, m_iHeight*0.5f);
		m_MapDraw.DrawMidText("입력 >>>", m_iWidth, m_iHeight*0.6f);

		cin >> Select;
		switch (Select)
		{
		case 1:
			MinesweeperGameStart();
			break;
		case 2:
			return;
		}
		system("pause");
	}

}

Minesweeper::~Minesweeper()
{
}
