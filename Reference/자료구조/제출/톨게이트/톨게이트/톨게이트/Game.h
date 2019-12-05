#pragma once
#include"Gate.h"
enum GAMESTATUS
{
	GAMESTATUS_STOP,
	GAMESTATUS_PLAYING
};


class Game
{
private:
	bool m_bGameStatus;
	Gate GateManager;
	MapDraw MapDrawManager;
public:
	void GameMain();
	void GameStart();
	Game();
	~Game();
};

