#include "ChessGameManager.h"



ChessGameManager::ChessGameManager()
{
	RoadList.reserve(MOVEPOSSIBILITYMAX);
}

void ShowRoad(HDC hdc, GAMESTATE gamestate, CHESSPIECE chesspiece, Position pos)
{
	switch (chesspiece)
	{
	case CHESSPIECE_PAWN:
		switch (gamestate) //�� �����̵� üũ
		{
		case GAMESTATE_WHITE_THINKING:
			if (pos.Position_x == 0 && pos.Position_y == CHESSBOARDBLOCKSIZE * 6)
				//��ĭ
				break;
		case GAMESTATE_BLACK_THINKING:
			if (pos.Position_x == 0 && pos.Position_y == CHESSBOARDBLOCKSIZE)
				//��ĭ	
				break;
		}
	
	case CHESSPIECE_KNIGHT:
		break;
	case CHESSPIECE_BISHOP:
		break;
	case CHESSPIECE_ROOK:
		break;
	case CHESSPIECE_QUEEN:
		break;
	case CHESSPIECE_KING:
		break;
	}
}

void ChessGameManager::RoadListSetting()
{

}


ChessGameManager::~ChessGameManager()
{
}

/*

	for (auto iter = RoadList.begin(); iter != RoadList.end(); iter++)
	{

	}
*/