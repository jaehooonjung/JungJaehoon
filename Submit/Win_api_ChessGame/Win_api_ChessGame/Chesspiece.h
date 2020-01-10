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
	int m_iChesspiece_Pos_x;
	int m_iChesspiece_Pos_y;
public:
	void Chesspieceinit(HDC hdc, string bitmapname, CHESSPIECECOLOR chesspiececolor);
	void ChessPieceSet(string bitmapname);
	void ChessPieceColorSet(CHESSPIECECOLOR chesspiececolor);
	Chesspiece();
	~Chesspiece();
};

