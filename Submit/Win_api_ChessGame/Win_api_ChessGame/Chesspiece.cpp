#include "Chesspiece.h"

Chesspiece::Chesspiece()
{
}

void Chesspiece::ChesspieceInit(HDC hdc, string bitmapname, CHESSPIECECOLOR chesspiececolor, int x, int y)
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
	ChessPiecePositionSet(x, y);
}

void Chesspiece::ChessPieceSet(string bitmapname)
{
	if (bitmapname == "block_b_00.bmp" || bitmapname == "block_w_00.bmp")
		m_ChessPiece = CHESSPIECE_PAWN;
	else if (bitmapname == "block_b_01.bmp" || bitmapname == "block_w_01.bmp")
		m_ChessPiece = CHESSPIECE_KNIGHT;
	else if (bitmapname == "block_b_02.bmp" || bitmapname == "block_w_02.bmp")
		m_ChessPiece = CHESSPIECE_BISHOP;
	else if (bitmapname == "block_b_03.bmp" || bitmapname == "block_w_03.bmp")
		m_ChessPiece = CHESSPIECE_ROOK;
	else if (bitmapname == "block_b_04.bmp" || bitmapname == "block_w_04.bmp")
		m_ChessPiece = CHESSPIECE_QUEEN;
	else if (bitmapname == "block_b_05.bmp" || bitmapname == "block_w_05.bmp")
		m_ChessPiece = CHESSPIECE_KING;
}

void Chesspiece::ChessPieceColorSet(CHESSPIECECOLOR chesspiececolor)
{
	switch (chesspiececolor)
	{
	case CHESSPIECECOLOR_WHITE:
		m_ChessPieceColor = CHESSPIECECOLOR_WHITE;
		break;
	case CHESSPIECECOLOR_BLACK:
		m_ChessPieceColor = CHESSPIECECOLOR_BLACK;
		break;
	}
}

void Chesspiece::ChessPiecePositionSet(int x, int y)
{
	m_ChesspiecePos.Position_x = x;
	m_ChesspiecePos.Position_y = y;
}

void Chesspiece::ChessPieceDraw(HDC hdc)
{
	TransparentBlt(hdc, m_ChesspiecePos.Position_x, m_ChesspiecePos.Position_y, CHESSPIECESIZE, CHESSPIECESIZE, m_MemDC, 0, 0, m_size.cx, m_size.cy, RGB(255, 0, 255));
}

bool Chesspiece::ChessPiecePositionCheck(int mouse_x, int mouse_y)
{
	if ((m_ChesspiecePos.Position_x < mouse_x) && (m_ChesspiecePos.Position_x + CHESSPIECESIZE > mouse_x) &&
		(m_ChesspiecePos.Position_y < mouse_y) && (m_ChesspiecePos.Position_y + CHESSPIECESIZE > mouse_y))
		return true;
	else
		return false;
}

Chesspiece::~Chesspiece()
{
	SelectObject(m_MemDC, m_phOldBitmap);
	DeleteObject(m_phImage);
	DeleteDC(m_MemDC);
}
