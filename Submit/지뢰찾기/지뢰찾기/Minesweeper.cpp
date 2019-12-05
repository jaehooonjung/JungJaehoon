#include "Minesweeper.h"



Minesweeper::Minesweeper()
{
	m_MapDraw.MapSizeSet(WIDTH_DEFUALT, HEIGHT_DEFUALT);
	m_iWidth = WIDTH_DEFUALT;
	m_iHeight = HEIGHT_DEFUALT;
}


void Minesweeper::AreaCheck(int x, int y)
{
	for (auto iter = AreaList.begin(); iter != AreaList.end(); iter++)
	{
		if ((*iter).x == x && (*iter).y == y)
		{
			if ((*iter).m_bCheckFlag == false)
				m_MapDraw.BlockDraw(x,y);
			else
			{
				//트리거 오픈시 이거는 나중에 작업하기
						
			}
			break;
		}

	}
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
		AreaCheck(m_Player.CursorPosition_X_Output(), m_Player.CursorPosition_Y_Output());
		m_Player.CursorMove(ch, m_iWidth, m_iHeight);
		break;
	case KEY_ESC:
		m_bGameState = false;
		return;
	case KEY_SPACEBAR:
		break;
	}
	//Update();
}

void Minesweeper::Update()
{
	m_MapDraw.GameMapDraw(m_iWidth, m_iHeight);
	//맵을 그리고 지뢰가 아닌걸로 판명된 지점을 지운다.
}

void Minesweeper::GameInitalize()
{
	MineManager::GetInstace()->MineCreate(m_iWidth, m_iHeight);
	AreaSet();
}

void Minesweeper::AreaSet()
{
	for (int y = 1; y < m_iHeight; y++)
	{
		for (int x = 1; x < m_iWidth; x++)
		{
			Area Tmp;
			Tmp.x = x, Tmp.y = y;
			if (MineManager::GetInstace()->MineCheck(x, y) != NULL)
				Tmp.m_bMineFlag = true;
			else
				Tmp.m_bMineFlag = false;
			Tmp.m_bCheckFlag = false;
			Tmp.m_strShape =  "■";
			AreaList.push_back(Tmp);
		}
	}


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
	delete MineManager::GetInstace();

}
