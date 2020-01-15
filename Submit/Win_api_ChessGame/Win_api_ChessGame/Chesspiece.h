#pragma once
#include"Mecro.h"

class Chesspiece
{
private:
	HDC m_MemDC;
	HBITMAP m_phImage;
	HBITMAP m_phOldBitmap;
	SIZE m_size;
	CHESSPIECE m_ChessPiece;
	CHESSPIECECOLOR m_ChessPieceColor;
	CHESSPIECESTATE m_ChessPieceState;
	Position m_ChesspiecePos;
public:
	void ChesspieceInit(HDC hdc, string bitmapname, CHESSPIECECOLOR chesspiececolor, int x, int y);
	void ChessPieceSet(string bitmapname);
	void ChessPieceColorSet(CHESSPIECECOLOR chesspiececolor);
	void ChessPiecePositionSet(int x, int y);
	void ChessPieceDraw(HDC hdc);
	bool ChessPiecePositionCheck(int mouse_x, int mouse_y);
	Chesspiece();
	inline CHESSPIECE ChessPieceOutput()
	{
		return m_ChessPiece;
	}
	inline Position ChessPiecePositionOutput()
	{
		return m_ChesspiecePos;
	}
	~Chesspiece();
};