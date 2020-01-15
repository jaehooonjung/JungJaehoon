#pragma once
#include "Chesspiece.h"

class ChesspieceManager
{
private:
	vector<Chesspiece*> m_WhiteChesspieceList;
	vector<Chesspiece*> m_BlackChesspieceList;
public:
	void ChesspieceManagerInit(HDC hdc);
	void ChesspieceCreate(HDC hdc, string bitmapnamewhite, string bitmapnameblack, CHESSPIECE chesspiece);
	void ChesspieceDraw(HDC hdc);
	void ChesspieceDelete();
	Chesspiece* ChesspieceSelect(GAMESTATE gamestate, int mouse_x, int mouse_y);
	ChesspieceManager();
	~ChesspieceManager();
};

