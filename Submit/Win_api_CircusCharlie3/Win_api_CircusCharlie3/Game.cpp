#include "Game.h"



Game::Game()
{
	m_Gamestate = GAMEINIT;
	m_Charaterstate = CHARACTER_STATE_MOVE;
}

void Game::init(HDC hdc)
{
	if (m_Gamestate != GAMEINIT)
		return;

	m_BackgroundManager.BackgroundInit(hdc);
	m_CharlieManager.CharlieInit(hdc);
	m_Gamestate = GAMEPLAYING;
}

void Game::Draw(HDC hdc)
{
	if (m_Gamestate != GAMEPLAYING)
		return;
	m_BackgroundManager.AllBackgroundDraw(hdc);
	m_CharlieManager.CharlieDraw(hdc);
}

void Game::KeyboardInputCheck(HWND hWnd)
{
	if (m_Gamestate != GAMEPLAYING)
		return;
	if (m_Charaterstate != CHARACTER_STATE_MOVE)
		return;

	int keyflag = NULL;
	if (GetKeyState(VK_LEFT) & 0x8000)
		keyflag = VK_LEFT;
	if (GetKeyState(VK_RIGHT) & 0x8000)
		keyflag = VK_RIGHT;


	if (keyflag == NULL)
		return;
	else
	{
		m_BackgroundManager.Move(keyflag);
		m_CharlieManager.CharlieMove(keyflag);
		// 각종 화살표에 맞는 작업
		InvalidateRect(hWnd, NULL, FALSE);
	}

}


Game::~Game()
{
}
