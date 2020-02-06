#pragma once
#include "ChesspieceManager.h"
#include "BlockManager.h"

class ChessGame
{
private:
	ChesspieceManager m_ChesspieceManager;
	BlockManager m_BlockManager;
	GAMESTATE m_GameState;
	Chesspiece* m_LastSelectChesspiece;
public:
	void Gameinit(HDC hdc, HWND hWnd);
	void GameDarw(HDC hdc);
	void MouseClick(POINT mouse, HWND hWnd);
	void TurnChange();
	bool Move(HWND hWnd);
	void GameStateChangeToPromotion();
	void Update(HWND hWnd,HDC hdc);
	void Promotion(HWND hWnd, HDC hdc);
	void CheckCheck(HWND hWnd);
	void WinCheck(HWND hWnd);
	ChessGame();
	inline void GameStateChangeToGameOver()
	{
		m_GameState = GAMESTATE_GAMEOVER;
	}
	~ChessGame();
};

