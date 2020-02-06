#include "ChessGame.h"



ChessGame::ChessGame()
{
	m_GameState = GAMESTATE_GAMEOVER;
}

void ChessGame::Gameinit(HDC hdc, HWND hWnd)
{
	if (m_GameState != GAMESTATE_GAMEOVER)
		return;
	DrawFlag = 0; 
	m_ChesspieceManager.ChesspieceManagerInit(hdc);
	m_BlockManager.BlockInit(hdc);
	m_BlockManager.MarkingBlockInit(hdc);
	m_LastSelectChesspiece = NULL;
	m_GameState = GAMESTATE_WHITE_THINKING;
	InvalidateRect(hWnd, NULL, TRUE);
}

void ChessGame::GameDarw(HDC hdc)
{
	if (m_GameState == GAMESTATE_GAMEOVER)
		return;
	m_BlockManager.BlockDraw(hdc);
	m_ChesspieceManager.AllChesspieceDraw(hdc);
	if (m_GameState == GAMESTATE_WHITE_PROMOTION || m_GameState == GAMESTATE_BLACK_PROMOTION)
		return;
	if (m_LastSelectChesspiece != NULL)
	{
		for (int i = 0; i < m_LastSelectChesspiece->PointListOutput().size(); i++)
		{
			m_BlockManager.MarkingBlockDraw(hdc, m_LastSelectChesspiece->PointListOutput()[i]);
		}
	}

}

void ChessGame::MouseClick(POINT mouse, HWND hWnd)
{
	switch (m_GameState)
	{
	case GAMESTATE_WHITE_THINKING:
	case GAMESTATE_BLACK_THINKING:
		if (m_LastSelectChesspiece != NULL)
		{		
			if (m_LastSelectChesspiece->ChessPieceMovePosSet(mouse) == true)
			{
				CheckCheck(hWnd);
				TurnChange();
				return;
			}
		}
		m_LastSelectChesspiece = m_ChesspieceManager.ChesspieceSelect(m_GameState, mouse);
		if (m_LastSelectChesspiece == NULL)
			return;
		m_ChesspieceManager.ChesspieceRoadSetting(m_LastSelectChesspiece);
		break;
	case GAMESTATE_WHITE_MOVEPHASE:
	case GAMESTATE_BLACK_MOVEPHASE:
		break;
	case GAMESTATE_GAMEOVER:
	case GAMESTATE_WHITE_PROMOTION:
	case GAMESTATE_BLACK_PROMOTION:
		return;
	}
}

void ChessGame::TurnChange()
{
	switch (m_GameState)
	{
	case GAMESTATE_GAMEOVER:
		break;
	case GAMESTATE_WHITE_THINKING:
		m_GameState = GAMESTATE_WHITE_MOVEPHASE;
		break;
	case GAMESTATE_WHITE_MOVEPHASE:
		m_GameState = GAMESTATE_BLACK_THINKING;
		break;
	case GAMESTATE_BLACK_THINKING:
		m_GameState = GAMESTATE_BLACK_MOVEPHASE;
		break;
	case GAMESTATE_BLACK_MOVEPHASE:
		m_GameState = GAMESTATE_WHITE_THINKING;
		break;
	case GAMESTATE_WHITE_PROMOTION:
		m_GameState = GAMESTATE_BLACK_THINKING;
		break;
	case GAMESTATE_BLACK_PROMOTION:
		m_GameState = GAMESTATE_WHITE_THINKING;
		break;
	}
}

bool ChessGame::Move(HWND hWnd)
{
	if (!(m_GameState == GAMESTATE_WHITE_MOVEPHASE || m_GameState == GAMESTATE_BLACK_MOVEPHASE))
		return false;

	if (m_LastSelectChesspiece->ChessPieceMove() == true)
	{
		m_ChesspieceManager.ChesspieceUpdate(m_LastSelectChesspiece); //���ݴ��� ü���� ����
		if (m_LastSelectChesspiece->ChessPieceOutput() == CHESSPIECE_PAWN) //���� ���θ�� ��ġ���� �Դ��� üũ
		{
			if (m_LastSelectChesspiece->PromotionCheck() == true)
			{
				GameStateChangeToPromotion();
				return true;
			}
		}
		m_LastSelectChesspiece = NULL;
			TurnChange();		
	}
		return true;
}

void ChessGame::GameStateChangeToPromotion()
{
	switch (m_GameState)
	{
	case GAMESTATE_GAMEOVER:
		return;
	case GAMESTATE_WHITE_MOVEPHASE:
		m_GameState = GAMESTATE_WHITE_PROMOTION;
		break;
	case GAMESTATE_BLACK_MOVEPHASE:
		m_GameState = GAMESTATE_BLACK_PROMOTION;
		break;
	}
}

void ChessGame::Update(HWND hWnd,HDC hdc)
{
	WinCheck(hWnd);
	Promotion(hWnd, hdc);
	//üũ ����
}

void ChessGame::Promotion(HWND hWnd, HDC hdc)
{
	if (!(m_GameState == GAMESTATE_WHITE_PROMOTION || m_GameState == GAMESTATE_BLACK_PROMOTION))
		return;
	while (1)
	{
		if (MessageBox(hWnd, TEXT("Queen���� ���θ���մϴ�."), TEXT("Promotion"), MB_OKCANCEL) == IDOK)
		{
			m_ChesspieceManager.ChesspiecePromotion(hdc, m_LastSelectChesspiece, CHESSPIECE_QUEEN);
			break;
		}
		if (MessageBox(hWnd, TEXT("Rook���� ���θ���մϴ�."), TEXT("Promotion"), MB_OKCANCEL) == IDOK)
		{
			m_ChesspieceManager.ChesspiecePromotion(hdc, m_LastSelectChesspiece, CHESSPIECE_ROOK);
			break;
		}
		if (MessageBox(hWnd, TEXT("Bishop���� ���θ���մϴ�."), TEXT("Promotion"), MB_OKCANCEL) == IDOK)
		{
			m_ChesspieceManager.ChesspiecePromotion(hdc, m_LastSelectChesspiece, CHESSPIECE_BISHOP);
			break;
		}
		if (MessageBox(hWnd, TEXT("Knight���� ���θ���մϴ�."), TEXT("Promotion"), MB_OKCANCEL) == IDOK)
		{
			m_ChesspieceManager.ChesspiecePromotion(hdc, m_LastSelectChesspiece, CHESSPIECE_KNIGHT);
			break;
		}
	}
	TurnChange();
	InvalidateRect(hWnd, NULL, TRUE);
}

void ChessGame::CheckCheck(HWND hWnd) 
{
	POINT LastPos = m_LastSelectChesspiece->ChessPiecePositionOutput();
	Chesspiece*tmp;
	tmp = m_LastSelectChesspiece;
	tmp->ChessPiecePositionSet(m_LastSelectChesspiece->DestinationPosOutput());
	m_ChesspieceManager.ChesspieceRoadSetting(tmp); //���������� ������ ü������ �̵�`���ݹ��� �缳��
	POINT Kingspos;
	switch (m_LastSelectChesspiece->ChessPieceColorOutput())
	{
	case CHESSPIECECOLOR_WHITE:
		Kingspos = m_ChesspieceManager.KingOutput(CHESSPIECECOLOR_BLACK)->ChessPiecePositionOutput();
		break;
	case CHESSPIECECOLOR_BLACK:
		Kingspos = m_ChesspieceManager.KingOutput(CHESSPIECECOLOR_WHITE)->ChessPiecePositionOutput();
		break;
	}

	if (tmp->CheckCheck(Kingspos) == true)
		MessageBox(hWnd, TEXT("üũ�Դϴ�."), TEXT("�˸�"), MB_OK);
	m_LastSelectChesspiece->PointListClear();
	m_LastSelectChesspiece->ChessPiecePositionSet(LastPos);
}

void ChessGame::WinCheck(HWND hWnd)
{
	if (m_ChesspieceManager.KingOutput(CHESSPIECECOLOR_BLACK) == NULL)
	{
		GameStateChangeToGameOver();
		MessageBox(hWnd, TEXT("���� üũ����Ʈ�Դϴ�."), TEXT("���ӿ���"), MB_OK);
	}
	if (m_ChesspieceManager.KingOutput(CHESSPIECECOLOR_WHITE) == NULL)
	{
		GameStateChangeToGameOver();
		MessageBox(hWnd, TEXT("���� üũ����Ʈ�Դϴ�."), TEXT("���ӿ���"), MB_OK);
	}

		
}

ChessGame::~ChessGame()
{
}
