#include "Chesspiece.h"

Chesspiece::Chesspiece()
{
}

void Chesspiece::ChesspieceInit(HDC hdc, CHESSPIECECOLOR chesspiececolor, POINT pos)
{
	string strtmp = ChessPieceSet(chesspiececolor);
	LPCTSTR tmp = strtmp.c_str();
	m_MemDC = CreateCompatibleDC(hdc);
	m_phImage = (HBITMAP)LoadImage(NULL, TEXT(tmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	m_phOldBitmap = (HBITMAP)SelectObject(m_MemDC, m_phImage);
	BITMAP bitmap;
	GetObject(m_phImage, sizeof(BITMAP), &bitmap);
	m_size.cx = bitmap.bmWidth;
	m_size.cy = bitmap.bmHeight;
	ChessPieceColorSet(chesspiececolor);
	ChessPiecePositionSet(pos);
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

void Chesspiece::ChessPiecePositionSet(POINT pos)
{
	m_ChesspiecePos.x = pos.x;
	m_ChesspiecePos.y = pos.y;
}

void Chesspiece::ChessPieceDraw(HDC hdc)
{
	TransparentBlt(hdc, m_ChesspiecePos.x, m_ChesspiecePos.y, CHESSPIECESIZE, CHESSPIECESIZE, m_MemDC, 0, 0, m_size.cx, m_size.cy, RGB(255, 0, 255));
}

bool Chesspiece::ChessPiecePositionCheck(POINT pos) 
{
	RECT Chesspiece = { m_ChesspiecePos.x,m_ChesspiecePos.y,m_ChesspiecePos.x + CHESSPIECESIZE,m_ChesspiecePos.y + CHESSPIECESIZE };
	return PtInRect(&Chesspiece, pos);
}

void Chesspiece::ChessPiecePointListInput(POINT pos)
{
	m_PointList.push_back(pos);
}

bool Chesspiece::ChessPieceMovePosSet(POINT pos)
{
	for (auto iter = m_PointList.begin(); iter != m_PointList.end(); iter++)
	{
		if (((*iter).x <= pos.x && (*iter).x+ CHESSBOARDBLOCKSIZE >= pos.x) && ((*iter).y <= pos.y && (*iter).y + CHESSBOARDBLOCKSIZE >= pos.y)  )
		{
			m_destinationPos.x = (*iter).x;
			m_destinationPos.y = (*iter).y;
			return true;
		}
	}
	return false;
}

void Chesspiece::PointListClear()
{
	m_PointList.clear();
}

bool Chesspiece::ChessPieceMove()
{
	if (m_destinationPos.x < m_ChesspiecePos.x)
		m_ChesspiecePos.x -= CHESSPIECEMOVESPEED;
	else if(m_destinationPos.x > m_ChesspiecePos.x)
		m_ChesspiecePos.x += CHESSPIECEMOVESPEED;

	if (m_destinationPos.y < m_ChesspiecePos.y)
		m_ChesspiecePos.y -= CHESSPIECEMOVESPEED;
	else if (m_destinationPos.y > m_ChesspiecePos.y)
		m_ChesspiecePos.y += CHESSPIECEMOVESPEED;

	if (m_destinationPos.x == m_ChesspiecePos.x && m_destinationPos.y == m_ChesspiecePos.y)
		return true;
	else
		return false;
}

void Chesspiece::DeleteBitmap()
{
	SelectObject(m_MemDC, m_phOldBitmap);
	DeleteObject(m_phImage);
	DeleteDC(m_MemDC);

}

bool Chesspiece::CheckCheck(POINT pos)
{
	for (auto iter = m_PointList.begin(); iter != m_PointList.end(); iter++)
	{
		if ((*iter).x == pos.x && (*iter).y == pos.y)
			return true;
	}
	return false;
}

Chesspiece::~Chesspiece()
{
	DeleteBitmap();
}

string Pawn::ChessPieceSet(CHESSPIECECOLOR chesspiececolor)
{
	m_ChessPiece = CHESSPIECE_PAWN;
	switch (chesspiececolor)
	{
	case CHESSPIECECOLOR_WHITE:
		return "block_w_00.bmp";
	case CHESSPIECECOLOR_BLACK:
		return "block_b_00.bmp";
	}
}

bool Pawn::PromotionCheck()
{
	switch (m_ChessPieceColor)
	{
	case CHESSPIECECOLOR_WHITE:
		if (m_ChesspiecePos.y == 0)
			return true;
		break;
	case CHESSPIECECOLOR_BLACK:
		if (m_ChesspiecePos.y == CHESSBOARDBLOCKSIZE * 7)
			return true;
		break;
	}
	return false;
}


string Knight::ChessPieceSet(CHESSPIECECOLOR chesspiececolor)
{
	m_ChessPiece = CHESSPIECE_KNIGHT;
	switch (chesspiececolor)
	{
	case CHESSPIECECOLOR_WHITE:
		return "block_w_01.bmp";
	case CHESSPIECECOLOR_BLACK:
		return "block_b_01.bmp";
	}
}

bool Knight::ChessPieceMove()
{
	if (m_destinationPos.x < m_ChesspiecePos.x)
		m_ChesspiecePos.x -= CHESSPIECEMOVESPEED;
	else if (m_destinationPos.x > m_ChesspiecePos.x)
		m_ChesspiecePos.x += CHESSPIECEMOVESPEED;

	if (m_destinationPos.y < m_ChesspiecePos.y)
		m_ChesspiecePos.y -= CHESSPIECEMOVESPEED;
	else if (m_destinationPos.y > m_ChesspiecePos.y)
		m_ChesspiecePos.y += CHESSPIECEMOVESPEED;

	if (m_destinationPos.x == m_ChesspiecePos.x && m_destinationPos.y == m_ChesspiecePos.y)
		return true;
	else
		return false;
}

string Bishop::ChessPieceSet(CHESSPIECECOLOR chesspiececolor)
{
	m_ChessPiece = CHESSPIECE_BISHOP;
	switch (chesspiececolor)
	{
	case CHESSPIECECOLOR_WHITE:
		return "block_w_02.bmp";
	case CHESSPIECECOLOR_BLACK:
		return "block_b_02.bmp";
	}
}
string Rook::ChessPieceSet(CHESSPIECECOLOR chesspiececolor)
{
	m_ChessPiece = CHESSPIECE_ROOK;
	switch (chesspiececolor)
	{
	case CHESSPIECECOLOR_WHITE:
		return "block_w_03.bmp";
	case CHESSPIECECOLOR_BLACK:
		return "block_b_03.bmp";
	}
}
string Queen::ChessPieceSet(CHESSPIECECOLOR chesspiececolor)
{
	m_ChessPiece = CHESSPIECE_QUEEN;
	switch (chesspiececolor)
	{
	case CHESSPIECECOLOR_WHITE:
		return "block_w_04.bmp";
	case CHESSPIECECOLOR_BLACK:
		return "block_b_04.bmp";
	}
}

string King::ChessPieceSet(CHESSPIECECOLOR chesspiececolor)
{
	m_ChessPiece = CHESSPIECE_KING;
	switch (chesspiececolor)
	{
	case CHESSPIECECOLOR_WHITE:
		return "block_w_05.bmp";
	case CHESSPIECECOLOR_BLACK:
		return "block_b_05.bmp";
	}
}

