#include "Game.h"

Game::Game()
{
	srand((unsigned)time(NULL));

	char buf[256];
	sprintf(buf, "mode con: cols=%d lines=%d", WIDTH*2, HEIGHT);
	system(buf);
}

void Game::GameMain()
{
	MapDrawManager.MenuDraw();
	switch (MapDrawManager.MenuSelectCursor(2, HEIGHT*0.2f, WIDTH*0.2f, HEIGHT*0.5f))	
	{
	case 1:
		GameStart();
		break;
	case 2:
		return;
	}

}

void Game::GameStart()
{
	char ch;
	m_bGameStatus = GAMESTATUS_PLAYING;
	GateManager.TimeSet();
	MapDrawManager.GateDraw();
	while (m_bGameStatus != GAMESTATUS_STOP)
	{
		GateManager.CurTimeSet();
		if (kbhit())
		{
			ch = getch();
			if (ch == SPACEBAR)
			{
				GateManager.CarCreate();
			}
			if (ch == ESC)
			{
				m_bGameStatus = GAMESTATUS_STOP;
			}	
		}
		GateManager.AllCarDraw();
	}
	system("cls");
	MapDrawManager.gotoxy(0, 0);
	GateManager.Dequeue();
}

Game::~Game()
{
}
