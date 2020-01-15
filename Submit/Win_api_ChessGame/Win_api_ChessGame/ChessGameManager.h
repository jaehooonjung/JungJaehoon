#pragma once
#include "BlockManager.h"

class ChessGameManager
{
private:
	vector<Position*>RoadList;
public:
	void ShowRoad(HDC hdc, GAMESTATE gamestate, CHESSPIECE chesspiece, Position pos);
	void RoadListSetting();
	ChessGameManager();
	~ChessGameManager();
};

//27