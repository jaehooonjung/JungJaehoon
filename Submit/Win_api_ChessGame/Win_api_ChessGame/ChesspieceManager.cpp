#include "ChesspieceManager.h"



ChesspieceManager::ChesspieceManager()
{
}

void ChesspieceManager::ChesspieceManagerInit(HDC hdc)
{
	ChesspieceCreate(hdc, "block_w_00.bmp", "block_b_00.bmp", CHESSPIECE_PAWN);
	ChesspieceCreate(hdc, "block_w_01.bmp", "block_b_01.bmp", CHESSPIECE_KNIGHT);
	ChesspieceCreate(hdc, "block_w_02.bmp", "block_b_02.bmp", CHESSPIECE_BISHOP);
	ChesspieceCreate(hdc, "block_w_03.bmp", "block_b_03.bmp", CHESSPIECE_ROOK);
	ChesspieceCreate(hdc, "block_w_04.bmp", "block_b_04.bmp", CHESSPIECE_QUEEN);
	ChesspieceCreate(hdc, "block_w_05.bmp", "block_b_05.bmp", CHESSPIECE_KING);
}

void ChesspieceManager::ChesspieceCreate(HDC hdc, string bitmapnamewhite, string bitmapnameblack, CHESSPIECE chesspiece)
{
	int white_x, white_y, black_x, black_y;
	int chesspiecenum;

	switch (chesspiece)
	{
	case CHESSPIECE_PAWN:
		chesspiecenum = CHESSPIECENUM_PAWN;
		white_x = 0, white_y = CHESSBOARDBLOCKSIZE * 6, black_x = 0, black_y = CHESSBOARDBLOCKSIZE;
		break;
	case CHESSPIECE_KNIGHT:
		chesspiecenum = CHESSPIECENUM_KNIGHT;
		white_x = CHESSBOARDBLOCKSIZE, white_y = CHESSBOARDBLOCKSIZE * 7, black_x = CHESSBOARDBLOCKSIZE, black_y = 0;
		break;
	case CHESSPIECE_BISHOP:
		chesspiecenum = CHESSPIECENUM_BISHOP;
		white_x = CHESSBOARDBLOCKSIZE * 2, white_y = CHESSBOARDBLOCKSIZE * 7, black_x = CHESSBOARDBLOCKSIZE * 2, black_y = 0;
		break;
	case CHESSPIECE_ROOK:
		chesspiecenum = CHESSPIECENUM_ROOK;
		white_x = 0, white_y = CHESSBOARDBLOCKSIZE * 7, black_x = 0, black_y = 0;
		break;
	case CHESSPIECE_QUEEN:
		chesspiecenum = CHESSPIECENUM_QUEEN;
		white_x = CHESSBOARDBLOCKSIZE * 3, white_y = CHESSBOARDBLOCKSIZE * 7, black_x = CHESSBOARDBLOCKSIZE * 3, black_y = 0;
		break;
	case CHESSPIECE_KING:
		chesspiecenum = CHESSPIECENUM_KING;
		white_x = CHESSBOARDBLOCKSIZE*4, white_y = CHESSBOARDBLOCKSIZE * 7, black_x = CHESSBOARDBLOCKSIZE * 4, black_y = 0;
		break;
	}

	for (int i = 0; i < chesspiecenum; i++)
	{

		Chesspiece*white = new Chesspiece;
		Chesspiece*black = new Chesspiece;
		white->ChesspieceInit(hdc, bitmapnamewhite, CHESSPIECECOLOR_WHITE, white_x, white_y);
		black->ChesspieceInit(hdc, bitmapnameblack, CHESSPIECECOLOR_BLACK, black_x, black_y);
		m_WhiteChesspieceList.push_back(white);
		m_WhiteChesspieceList.push_back(black);

		switch (chesspiece)
		{
		case CHESSPIECE_PAWN:
			white_x += CHESSBOARDBLOCKSIZE, black_x += CHESSBOARDBLOCKSIZE;
			break;
		case CHESSPIECE_KNIGHT:
			white_x += CHESSBOARDBLOCKSIZE*5, black_x += CHESSBOARDBLOCKSIZE*5;
			break;
		case CHESSPIECE_BISHOP:
			white_x += CHESSBOARDBLOCKSIZE*3, black_x += CHESSBOARDBLOCKSIZE*3;
			break;
		case CHESSPIECE_ROOK:
			white_x += CHESSBOARDBLOCKSIZE*7, black_x += CHESSBOARDBLOCKSIZE*7;
			break;
		case CHESSPIECE_QUEEN:
			break;
		case CHESSPIECE_KING:
			break;
		}
	}
}

void ChesspieceManager::ChesspieceDraw(HDC hdc)
{
	for (auto iter = m_WhiteChesspieceList.begin(); iter != m_WhiteChesspieceList.end(); iter++)
	{
		(*iter)->ChessPieceDraw(hdc);
	}
	for (auto iter = m_BlackChesspieceList.begin(); iter != m_BlackChesspieceList.end(); iter++)
	{
		(*iter)->ChessPieceDraw(hdc);
	}

}

void ChesspieceManager::ChesspieceDelete()
{
	for (auto iter = m_WhiteChesspieceList.begin(); iter != m_WhiteChesspieceList.end(); iter++)
	{
		delete (*iter);
	}
	for (auto iter = m_BlackChesspieceList.begin(); iter != m_BlackChesspieceList.end(); iter++)
	{
		delete (*iter);
	}
	m_WhiteChesspieceList.clear();
	m_BlackChesspieceList.clear();
}

ChesspieceManager::~ChesspieceManager()
{
	ChesspieceDelete();
}
