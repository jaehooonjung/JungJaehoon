#pragma once
#include"Player.h"
#include"AreaManager.h"
class Minesweeper
{
private:
	int m_iWidth;
	int m_iHeight;
	bool m_bGameState;
	MapDraw m_MapDraw;
	Player m_Player;
public:
	void MinesweeperMenu();
	void MinesweeperGameStart();
	void GameInitalize();
	void GameEnd();
	void input();
	void EraseBackUp(int x, int y);
	void ClearCheck();
	Minesweeper();
	~Minesweeper();
};