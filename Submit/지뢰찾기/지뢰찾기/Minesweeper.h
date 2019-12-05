#pragma once
#include"Player.h"
#include"MineManager.h"
struct Area
{
	int x;
	int y;
	string m_strShape;
	bool m_bMineFlag;
	bool m_bCheckFlag;
};

class Minesweeper
{
private:
	vector<Area>AreaList;
	int m_iWidth;
	int m_iHeight;
	bool m_bGameState;
	MapDraw m_MapDraw;
	Player m_Player;
public:
	void MinesweeperMenu();
	void MinesweeperGameStart();
	void GameInitalize();
	void AreaSet();
	void input();
	void Update();
	void EraseBackUp(int x, int y);
	void AreaCheck(int x, int y);
	Minesweeper();
	~Minesweeper();
};