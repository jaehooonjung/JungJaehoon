#pragma once
#include "Background.h"
#include "Charlie.h"

class Game
{
private:
	int m_iMoveDistance;
	JumpTimeInfo m_JumpTimeInfo;
	GAMESTATE m_Gamestate;
	CHARACTER_STATE m_Charaterstate;
	Background m_BackgroundManager;
	Charlie m_CharlieManager;
public:
	void init(HDC hdc);
	void Draw(HDC hdc);
	void KeyboardInputCheck(HWND hWnd);
	void Move(int keyflag);
	void Jump(HWND hWnd);
	void DistanceUpdate(int keyflag);
	void IntersectTest();
	void GameReset();
	Game();
	~Game();
};

