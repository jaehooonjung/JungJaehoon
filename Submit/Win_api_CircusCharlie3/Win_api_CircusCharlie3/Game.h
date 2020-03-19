#pragma once
#include "Background.h"
#include "Charlie.h"

class Game
{
private:
	GAMESTATE m_Gamestate;
	CHARACTER_STATE m_Charaterstate;
	Background m_BackgroundManager;
	Charlie m_CharlieManager;
public:
	void init(HDC hdc);
	void Draw(HDC hdc);
	void KeyboardInputCheck(HWND hWnd);
	Game();
	~Game();
};

