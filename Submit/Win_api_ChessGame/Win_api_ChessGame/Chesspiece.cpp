#include "Chesspiece.h"

Chesspiece::Chesspiece()
{
}

void Chesspiece::Chesspieceinit(HDC hdc, string bitmapname, CHESSPIECECOLOR chesspiececolor)
{
	LPCTSTR tmp = bitmapname.c_str();
	m_MemDC = CreateCompatibleDC(hdc);
	m_phImage = (HBITMAP)LoadImage(NULL, TEXT(tmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	m_phOldBitmap = (HBITMAP)SelectObject(m_MemDC, m_phImage);
	BITMAP bitmap;
	GetObject(m_phImage, sizeof(BITMAP), &bitmap);
	m_size.cx = bitmap.bmWidth;
	m_size.cy = bitmap.bmHeight;
	ChessPieceSet(bitmapname);
	ChessPieceColorSet(chesspiececolor);
	m_ChessPieceState = CHESSPIECESTATUS_LIVE;
}

void Chesspiece::ChessPieceSet(string bitmapname)
{
	if (bitmapname == "block_b_00" || bitmapname == "block_w_00")
		m_ChessPiece = CHESSPIECE_PAWN;
	else if (bitmapname == "block_b_01" || bitmapname == "block_w_01")
		m_ChessPiece = CHESSPIECE_KNIGHT;
	else if (bitmapname == "block_b_02" || bitmapname == "block_w_02")
		m_ChessPiece = CHESSPIECE_BISHOP;
	else if (bitmapname == "block_b_03" || bitmapname == "block_w_03")
		m_ChessPiece = CHESSPIECE_ROOK;
	else if (bitmapname == "block_b_04" || bitmapname == "block_w_04")
		m_ChessPiece = CHESSPIECE_QUEEN;
	else if (bitmapname == "block_b_05" || bitmapname == "block_w_05")
		m_ChessPiece = CHESSPIECE_KING;
}

void Chesspiece::ChessPieceColorSet(CHESSPIECECOLOR chesspiececolor)
{
	switch (chesspiececolor)
	{
	case CHESSPIECECOLOR_WHITHT:
		m_ChessPieceColor = CHESSPIECECOLOR_WHITHT;
		break;
	case CHESSPIECECOLOR_BLACK:
		m_ChessPieceColor = CHESSPIECECOLOR_BLACK;
		break;
	}
}


Chesspiece::~Chesspiece()
{
}
