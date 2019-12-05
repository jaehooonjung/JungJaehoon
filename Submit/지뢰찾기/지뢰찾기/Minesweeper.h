#pragma once
#include"Player.h"
#include"MineManager.h"
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
	void input();
	void Update();
	Minesweeper();
	~Minesweeper();
};

