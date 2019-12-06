#include "Minesweeper.h"



Minesweeper::Minesweeper()
{
	m_MapDraw.MapSizeSet(WIDTH_DEFUALT, HEIGHT_DEFUALT);
	m_iWidth = WIDTH_DEFUALT;
	m_iHeight = HEIGHT_DEFUALT;
}


void Minesweeper::EraseBackUp(int x, int y)
{
	m_MapDraw.DrawPoint(AreaManager::GetInstace()->AreaShapeOutput(x, y), x, y);
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
		EraseBackUp(m_Player.CursorPosition_X_Output(), m_Player.CursorPosition_Y_Output());
		m_Player.CursorMove(ch, m_iWidth, m_iHeight);
		break;
	case KEY_ESC:
		m_bGameState = false;
		return;
	case KEY_SPACEBAR:
		if (MineManager::GetInstace()->MineCheck(m_Player.CursorPosition_X_Output(), m_Player.CursorPosition_Y_Output()) == NULL)
		{
			AreaManager::GetInstace()->AreaCheck(m_Player.CursorPosition_X_Output(), m_Player.CursorPosition_Y_Output());
		}
		else
		{
			m_MapDraw.MineDraw(m_Player.CursorPosition_X_Output(), m_Player.CursorPosition_Y_Output());
			getch();
			//m_bGameState = false;
		}
		break;
	}
}

void Minesweeper::GameInitalize()
{
	m_Player.PlayerInitialize("☆", m_iWidth, m_iHeight);
	MineManager::GetInstace()->MineCreate(m_iWidth, m_iHeight);
	AreaManager::GetInstace()->AreaSet(m_iWidth, m_iHeight);
}

void Minesweeper::GameEnd()
{
	m_Player.PlayerInitialize("☆", m_iWidth, m_iHeight);
	MineManager::GetInstace()->DeleteMineAll();
	AreaManager::GetInstace()->DeleteAreaAll();
}


void Minesweeper::MinesweeperGameStart()
{
	m_bGameState = true;
	m_MapDraw.GameMapDraw(m_iWidth, m_iHeight);
	GameInitalize();
	while (m_bGameState)
	{
		m_Player.DrawCursor();
		input();
	}
	GameEnd();
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
	}
}

Minesweeper::~Minesweeper()
{
	delete MineManager::GetInstace();
	delete AreaManager::GetInstace();
}
