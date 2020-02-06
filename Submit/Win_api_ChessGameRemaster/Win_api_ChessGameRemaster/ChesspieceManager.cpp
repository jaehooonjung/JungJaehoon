#include "ChesspieceManager.h"



ChesspieceManager::ChesspieceManager()
{
}

void ChesspieceManager::ChesspieceManagerInit(HDC hdc)
{
	if(m_WhiteChesspieceList.size() != NULL || m_BlackChesspieceList.size() != NULL)
		AllChesspieceDelete();
	ChesspieceCreate(hdc, CHESSPIECE_PAWN);
	ChesspieceCreate(hdc, CHESSPIECE_KNIGHT);
	ChesspieceCreate(hdc, CHESSPIECE_BISHOP);
	ChesspieceCreate(hdc, CHESSPIECE_ROOK);
	ChesspieceCreate(hdc, CHESSPIECE_QUEEN);
	ChesspieceCreate(hdc, CHESSPIECE_KING);
}

void ChesspieceManager::ChesspieceCreate(HDC hdc, CHESSPIECE chesspiece)
{
	POINT white, black;
	int chesspiecenum;

	switch (chesspiece)
	{
	case CHESSPIECE_PAWN:
		chesspiecenum = CHESSPIECENUM_PAWN;
		white.x = 0, white.y = CHESSBOARDBLOCKSIZE * 6, black.x = 0, black.y = CHESSBOARDBLOCKSIZE;
		break;
	case CHESSPIECE_KNIGHT:
		chesspiecenum = CHESSPIECENUM_KNIGHT;
		white.x = CHESSBOARDBLOCKSIZE, white.y = CHESSBOARDBLOCKSIZE * 7, black.x = CHESSBOARDBLOCKSIZE, black.y = 0;
		break;
	case CHESSPIECE_BISHOP:
		chesspiecenum = CHESSPIECENUM_BISHOP;
		white.x = CHESSBOARDBLOCKSIZE * 2, white.y = CHESSBOARDBLOCKSIZE * 7, black.x = CHESSBOARDBLOCKSIZE * 2, black.y = 0;
		break;
	case CHESSPIECE_ROOK:
		chesspiecenum = CHESSPIECENUM_ROOK;
		white.x = 0, white.y = CHESSBOARDBLOCKSIZE * 7, black.x = 0, black.y = 0;
		break;
	case CHESSPIECE_QUEEN:
		chesspiecenum = CHESSPIECENUM_QUEEN;
		white.x = CHESSBOARDBLOCKSIZE * 3, white.y = CHESSBOARDBLOCKSIZE * 7, black.x = CHESSBOARDBLOCKSIZE * 3, black.y = 0;
		break;
	case CHESSPIECE_KING:
		chesspiecenum = CHESSPIECENUM_KING;
		white.x = CHESSBOARDBLOCKSIZE * 4, white.y = CHESSBOARDBLOCKSIZE * 7, black.x = CHESSBOARDBLOCKSIZE * 4, black.y = 0;
		break;
	}

	for (int i = 0; i < chesspiecenum; i++)
	{
		Chesspiece*whitepiece;
		Chesspiece*blackpiece;
		if (chesspiece == CHESSPIECE_PAWN)
		{
			whitepiece = new Pawn;
			blackpiece = new Pawn;
		}
		else if (chesspiece == CHESSPIECE_KNIGHT)
		{
			whitepiece = new Knight;
			blackpiece = new Knight;
		}
		else if (chesspiece == CHESSPIECE_BISHOP)
		{
			whitepiece = new Bishop;
			blackpiece = new Bishop;
		}
		else if (chesspiece == CHESSPIECE_ROOK)
		{
			whitepiece = new Rook;
			blackpiece = new Rook;
		}
		else if (chesspiece == CHESSPIECE_QUEEN)
		{
			whitepiece = new Queen;
			blackpiece = new Queen;
		}
		else if (chesspiece == CHESSPIECE_KING)
		{
			whitepiece = new King;
			blackpiece = new King;
		}
		whitepiece->ChesspieceInit(hdc, CHESSPIECECOLOR_WHITE, white);
		blackpiece->ChesspieceInit(hdc, CHESSPIECECOLOR_BLACK, black);
		m_WhiteChesspieceList.push_back(whitepiece);
		m_BlackChesspieceList.push_back(blackpiece);
		switch (chesspiece)
		{
		case CHESSPIECE_PAWN:
			white.x += CHESSBOARDBLOCKSIZE, black.x += CHESSBOARDBLOCKSIZE;
			break;
		case CHESSPIECE_KNIGHT:
			white.x += CHESSBOARDBLOCKSIZE * 5, black.x += CHESSBOARDBLOCKSIZE * 5;
			break;
		case CHESSPIECE_BISHOP:
			white.x += CHESSBOARDBLOCKSIZE * 3, black.x += CHESSBOARDBLOCKSIZE * 3;
			break;
		case CHESSPIECE_ROOK:
			white.x += CHESSBOARDBLOCKSIZE * 7, black.x += CHESSBOARDBLOCKSIZE * 7;
			break;
		}
	}
}

void ChesspieceManager::AllChesspieceDraw(HDC hdc)
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

void ChesspieceManager::AllChesspieceDelete()
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

Chesspiece* ChesspieceManager::ChesspieceSelect(GAMESTATE gamestate, POINT pos)
{
	switch (gamestate)
	{
	case GAMESTATE_WHITE_THINKING:
		for (auto iter = m_WhiteChesspieceList.begin(); iter != m_WhiteChesspieceList.end(); iter++)
		{
			if ((*iter)->ChessPiecePositionCheck(pos) == true)
				return *iter;
		}
		break;
	case GAMESTATE_BLACK_THINKING:
		for (auto iter = m_BlackChesspieceList.begin(); iter != m_BlackChesspieceList.end(); iter++)
		{
			if ((*iter)->ChessPiecePositionCheck(pos) == true)
				return *iter;
		}
		break;
	}
	return NULL;
}

bool ChesspieceManager::ChesspieceCheckSameColor(POINT pos, CHESSPIECECOLOR chesspiececolor)
{
	switch (chesspiececolor)
	{
	case CHESSPIECECOLOR_WHITE:
		for (auto iter = m_WhiteChesspieceList.begin(); iter != m_WhiteChesspieceList.end(); iter++)
		{
			if (((*iter)->ChessPiecePositionOutput().x == pos.x) && ((*iter)->ChessPiecePositionOutput().y == pos.y))
				return true;
		}
		break;
	case CHESSPIECECOLOR_BLACK:
		for (auto iter = m_BlackChesspieceList.begin(); iter != m_BlackChesspieceList.end(); iter++)
		{
			if (((*iter)->ChessPiecePositionOutput().x == pos.x) && ((*iter)->ChessPiecePositionOutput().y == pos.y))
				return true;
		}
		break;
	}
	return false;
}

bool ChesspieceManager::ChesspieceCheckAnotherColor(POINT pos, CHESSPIECECOLOR chesspiececolor)
{
	switch (chesspiececolor)
	{
	case CHESSPIECECOLOR_WHITE:
		for (auto iter = m_BlackChesspieceList.begin(); iter != m_BlackChesspieceList.end(); iter++)
		{
			if (((*iter)->ChessPiecePositionOutput().x == pos.x) && ((*iter)->ChessPiecePositionOutput().y == pos.y))
				return true;
		}
		break;
	case CHESSPIECECOLOR_BLACK:
		for (auto iter = m_WhiteChesspieceList.begin(); iter != m_WhiteChesspieceList.end(); iter++)
		{
			if (((*iter)->ChessPiecePositionOutput().x == pos.x) && ((*iter)->ChessPiecePositionOutput().y == pos.y))
				return true;
		}
		break;
	}
	return false;

}

void ChesspieceManager::ChesspieceRoadSetting(Chesspiece*selectedchesspiece)
{
	selectedchesspiece->PointListClear();
	switch (selectedchesspiece->ChessPieceOutput())
	{
	case CHESSPIECE_PAWN:
		switch (selectedchesspiece->ChessPieceColorOutput())
		{
		case CHESSPIECECOLOR_WHITE:
			if (selectedchesspiece->ChessPiecePositionOutput().y == 300)
				RoadCheckPawn(2, selectedchesspiece);
			else
				RoadCheckPawn(1, selectedchesspiece);
			break;
		case CHESSPIECECOLOR_BLACK:
			if (selectedchesspiece->ChessPiecePositionOutput().y == 50)
				RoadCheckPawn(2, selectedchesspiece);
			else
				RoadCheckPawn(1, selectedchesspiece);
			break;
		}
		break;
	case CHESSPIECE_KNIGHT:
		RoadCheckKnight(selectedchesspiece);
		break;
	case CHESSPIECE_BISHOP:
		RoadCheckUpperLeft(7, selectedchesspiece);
		RoadCheckUpperRight(7, selectedchesspiece);
		RoadCheckLowerLeft(7, selectedchesspiece);
		RoadCheckLowerRight(7, selectedchesspiece);
		break;
	case CHESSPIECE_ROOK:
		RoadCheckTop(7, selectedchesspiece);
		RoadCheckLeft(7, selectedchesspiece);
		RoadCheckRight(7, selectedchesspiece);
		RoadCheckBottom(7, selectedchesspiece);
		break;
	case CHESSPIECE_QUEEN:
		RoadCheckUpperLeft(7, selectedchesspiece);
		RoadCheckTop(7, selectedchesspiece);
		RoadCheckUpperRight(7, selectedchesspiece);
		RoadCheckLeft(7, selectedchesspiece);
		RoadCheckRight(7, selectedchesspiece);
		RoadCheckLowerLeft(7, selectedchesspiece);
		RoadCheckBottom(7, selectedchesspiece);
		RoadCheckLowerRight(7, selectedchesspiece);
		break;
	case CHESSPIECE_KING:
		RoadCheckUpperLeft(1, selectedchesspiece);
		RoadCheckTop(1, selectedchesspiece);
		RoadCheckUpperRight(1, selectedchesspiece);
		RoadCheckLeft(1, selectedchesspiece);
		RoadCheckRight(1, selectedchesspiece);
		RoadCheckLowerLeft(1, selectedchesspiece);
		RoadCheckBottom(1, selectedchesspiece);
		RoadCheckLowerRight(1, selectedchesspiece);
		break;
	}
}

void ChesspieceManager::RoadCheckUpperLeft(int length, Chesspiece*selectedchesspiece)
{
	POINT postmp = selectedchesspiece->ChessPiecePositionOutput();
	for (int i = 0; i < length; i++)
	{
		postmp.x -= CHESSBOARDBLOCKSIZE;
		postmp.y -= CHESSBOARDBLOCKSIZE;
		if (postmp.y < 0 || postmp.x < 0)
			break;
		if (ChesspieceCheckSameColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == false)
		{
			selectedchesspiece->ChessPiecePointListInput(postmp);
			if (ChesspieceCheckAnotherColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == true)
				break;
		}
		else
			break;
	}
}

void ChesspieceManager::RoadCheckTop(int length, Chesspiece*selectedchesspiece)
{
	POINT postmp = selectedchesspiece->ChessPiecePositionOutput();
	for (int i = 0; i < length; i++)
	{
		postmp.y -= CHESSBOARDBLOCKSIZE;
		if (postmp.y < 0)
			break;
		if (ChesspieceCheckSameColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == false)
		{
			selectedchesspiece->ChessPiecePointListInput(postmp);
			if (ChesspieceCheckAnotherColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == true)
				break;
		}
		else
			break;
	}
}

void ChesspieceManager::RoadCheckUpperRight(int length, Chesspiece*selectedchesspiece)
{
	POINT postmp = selectedchesspiece->ChessPiecePositionOutput();
	for (int i = 0; i < length; i++)
	{
		postmp.x += CHESSBOARDBLOCKSIZE;
		postmp.y -= CHESSBOARDBLOCKSIZE;
		if (postmp.y > CHESSBOARDBLOCKSIZE * 7 || postmp.x > CHESSBOARDBLOCKSIZE * 7)
			break;
		if (ChesspieceCheckSameColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == false)
		{
			selectedchesspiece->ChessPiecePointListInput(postmp);
			if (ChesspieceCheckAnotherColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == true)
				break;
		}
		else
			break;
	}
}

void ChesspieceManager::RoadCheckLeft(int length, Chesspiece*selectedchesspiece)
{
	POINT postmp = selectedchesspiece->ChessPiecePositionOutput();
	for (int i = 0; i < length; i++)
	{
		postmp.x -= CHESSBOARDBLOCKSIZE;
		if (postmp.x < 0)
			break;
		if (ChesspieceCheckSameColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == false)
		{
			selectedchesspiece->ChessPiecePointListInput(postmp);
			if (ChesspieceCheckAnotherColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == true)
				break;
		}
		else
			break;
	}
}

void ChesspieceManager::RoadCheckRight(int length, Chesspiece*selectedchesspiece)
{
	POINT postmp = selectedchesspiece->ChessPiecePositionOutput();
	for (int i = 0; i < length; i++)
	{
		postmp.x += CHESSBOARDBLOCKSIZE;
		if (postmp.x > CHESSBOARDBLOCKSIZE * 7)
			break;
		if (ChesspieceCheckSameColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == false)
		{
			selectedchesspiece->ChessPiecePointListInput(postmp);
			if (ChesspieceCheckAnotherColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == true)
				break;
		}
		else
			break;
	}
}

void ChesspieceManager::RoadCheckLowerLeft(int length, Chesspiece*selectedchesspiece)
{
	POINT postmp = selectedchesspiece->ChessPiecePositionOutput();
	for (int i = 0; i < length; i++)
	{
		postmp.x -= CHESSBOARDBLOCKSIZE;
		postmp.y += CHESSBOARDBLOCKSIZE;
		if (postmp.y > CHESSBOARDBLOCKSIZE * 7 || postmp.x < 0)
			break;
		if (ChesspieceCheckSameColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == false)
		{
			selectedchesspiece->ChessPiecePointListInput(postmp);
			if (ChesspieceCheckAnotherColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == true)
				break;
		}
		else
			break;
	}
}

void ChesspieceManager::RoadCheckBottom(int length, Chesspiece*selectedchesspiece)
{
	POINT postmp = selectedchesspiece->ChessPiecePositionOutput();
	for (int i = 0; i < length; i++)
	{
		postmp.y += CHESSBOARDBLOCKSIZE;
		if (postmp.y > CHESSBOARDBLOCKSIZE * 7)
			break;
		if (ChesspieceCheckSameColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == false)
		{
				selectedchesspiece->ChessPiecePointListInput(postmp);
				if (ChesspieceCheckAnotherColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == true)
					break;
		}
		else
			break;
	}
}

void ChesspieceManager::RoadCheckLowerRight(int length, Chesspiece*selectedchesspiece)
{
	POINT postmp = selectedchesspiece->ChessPiecePositionOutput();
	for (int i = 0; i < length; i++)
	{
		postmp.x += CHESSBOARDBLOCKSIZE;
		postmp.y += CHESSBOARDBLOCKSIZE;
		if (postmp.y > CHESSBOARDBLOCKSIZE * 7 || postmp.x > CHESSBOARDBLOCKSIZE * 7)
			break;
		if (ChesspieceCheckSameColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == false)
		{
			selectedchesspiece->ChessPiecePointListInput(postmp);
			if (ChesspieceCheckAnotherColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == true)
				break;
		}
		else
			break;
	}
}

void ChesspieceManager::RoadCheckKnight(Chesspiece*selectedchesspiece)
{
	POINT postmp;
	POINT CPpos = selectedchesspiece->ChessPiecePositionOutput();
	postmp.x = CPpos.x - CHESSBOARDBLOCKSIZE;
	postmp.y = CPpos.y - (CHESSBOARDBLOCKSIZE * 2);
	if (!(postmp.y < 0 || postmp.x < 0) && ChesspieceCheckSameColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == false)
		selectedchesspiece->ChessPiecePointListInput(postmp);

	postmp.x = CPpos.x + CHESSBOARDBLOCKSIZE;
	postmp.y = CPpos.y - (CHESSBOARDBLOCKSIZE * 2);
	if (!(postmp.y < 0 || postmp.x > CHESSBOARDBLOCKSIZE * 7) && ChesspieceCheckSameColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == false)
		selectedchesspiece->ChessPiecePointListInput(postmp);

	postmp.x = CPpos.x - (CHESSBOARDBLOCKSIZE *2);
	postmp.y = CPpos.y - CHESSBOARDBLOCKSIZE;
	if (!(postmp.y < 0 || postmp.x < 0) && ChesspieceCheckSameColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == false)
		selectedchesspiece->ChessPiecePointListInput(postmp);

	postmp.x = CPpos.x + (CHESSBOARDBLOCKSIZE * 2);
	postmp.y = CPpos.y - CHESSBOARDBLOCKSIZE;
	if (!(postmp.y < 0 || postmp.x > CHESSBOARDBLOCKSIZE * 7) && ChesspieceCheckSameColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == false)
		selectedchesspiece->ChessPiecePointListInput(postmp);

	postmp.x = CPpos.x - (CHESSBOARDBLOCKSIZE * 2);
	postmp.y = CPpos.y + CHESSBOARDBLOCKSIZE;
	if (!(postmp.y > CHESSBOARDBLOCKSIZE * 7 || postmp.x < 0) && ChesspieceCheckSameColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == false)
		selectedchesspiece->ChessPiecePointListInput(postmp);


	postmp.x = CPpos.x + (CHESSBOARDBLOCKSIZE * 2);
	postmp.y = CPpos.y + CHESSBOARDBLOCKSIZE;
	if (!(postmp.y > CHESSBOARDBLOCKSIZE * 7 || postmp.x > CHESSBOARDBLOCKSIZE * 7) && ChesspieceCheckSameColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == false)
		selectedchesspiece->ChessPiecePointListInput(postmp);

	postmp.x = CPpos.x - CHESSBOARDBLOCKSIZE;
	postmp.y = CPpos.y + (CHESSBOARDBLOCKSIZE * 2);
	if (!(postmp.y > CHESSBOARDBLOCKSIZE * 7 || postmp.x < 0) && ChesspieceCheckSameColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == false)
		selectedchesspiece->ChessPiecePointListInput(postmp);

	postmp.x = CPpos.x + CHESSBOARDBLOCKSIZE;
	postmp.y = CPpos.y + (CHESSBOARDBLOCKSIZE * 2);
	if (!(postmp.y > CHESSBOARDBLOCKSIZE * 7 || postmp.x > CHESSBOARDBLOCKSIZE * 7) && ChesspieceCheckSameColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == false)
		selectedchesspiece->ChessPiecePointListInput(postmp);
}

void ChesspieceManager::RoadCheckPawn(int length, Chesspiece*selectedchesspiece)
{
	POINT postmp = selectedchesspiece->ChessPiecePositionOutput();
	switch (selectedchesspiece->ChessPieceColorOutput())
	{
	case CHESSPIECECOLOR_WHITE:
		for (int i = 0; i < length; i++)
		{
			postmp.y -= CHESSBOARDBLOCKSIZE;
			if (postmp.y < 0)
				break;
			if (ChesspieceCheckSameColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == false && ChesspieceCheckAnotherColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == false)
				selectedchesspiece->ChessPiecePointListInput(postmp);
			else
				break;
		}
		postmp.x = selectedchesspiece->ChessPiecePositionOutput().x - CHESSBOARDBLOCKSIZE;
		postmp.y = selectedchesspiece->ChessPiecePositionOutput().y - CHESSBOARDBLOCKSIZE;
		if (!(postmp.y < 0 || postmp.x < 0))
		{
			if (ChesspieceCheckSameColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == false && ChesspieceCheckAnotherColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == true)
				selectedchesspiece->ChessPiecePointListInput(postmp);
		}
		postmp.x = selectedchesspiece->ChessPiecePositionOutput().x + CHESSBOARDBLOCKSIZE;
		postmp.y = selectedchesspiece->ChessPiecePositionOutput().y - CHESSBOARDBLOCKSIZE;
		if (!(postmp.x < 0 || postmp.x > CHESSBOARDBLOCKSIZE * 7))
		{
			if (ChesspieceCheckSameColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == false && ChesspieceCheckAnotherColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == true)
				selectedchesspiece->ChessPiecePointListInput(postmp);
		}
		break;
	case CHESSPIECECOLOR_BLACK:
		for (int i = 0; i < length; i++)
		{
			postmp.y += CHESSBOARDBLOCKSIZE;
			if (postmp.y > CHESSBOARDBLOCKSIZE * 7)
				break;
			if (ChesspieceCheckSameColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == false && ChesspieceCheckAnotherColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == false)
				selectedchesspiece->ChessPiecePointListInput(postmp);
			else
				break;
		}
		postmp.x = selectedchesspiece->ChessPiecePositionOutput().x + CHESSBOARDBLOCKSIZE;
		postmp.y = selectedchesspiece->ChessPiecePositionOutput().y + CHESSBOARDBLOCKSIZE;
		if (!(postmp.y > CHESSBOARDBLOCKSIZE * 7 || postmp.x > CHESSBOARDBLOCKSIZE * 7))
		{
			if (ChesspieceCheckSameColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == false && ChesspieceCheckAnotherColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == true)
				selectedchesspiece->ChessPiecePointListInput(postmp);
		}
		postmp.x = selectedchesspiece->ChessPiecePositionOutput().x - CHESSBOARDBLOCKSIZE;
		postmp.y = selectedchesspiece->ChessPiecePositionOutput().y + CHESSBOARDBLOCKSIZE;
		if (!(postmp.y > CHESSBOARDBLOCKSIZE * 7 || postmp.x < 0))
		{
			if (ChesspieceCheckSameColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == false && ChesspieceCheckAnotherColor(postmp, selectedchesspiece->ChessPieceColorOutput()) == true)
				selectedchesspiece->ChessPiecePointListInput(postmp);
		}
		break;
	}
}

void ChesspieceManager::ChesspieceUpdate(Chesspiece*selectedchesspiece)
{
	POINT lastmovedchesspiecepos = selectedchesspiece->ChessPiecePositionOutput();
	RECT lastmovedchesspiecerect = { lastmovedchesspiecepos.x,lastmovedchesspiecepos.y,lastmovedchesspiecepos.x + CHESSPIECESIZE ,lastmovedchesspiecepos.y + CHESSPIECESIZE };
	RECT tmprect,tmprect2;

	switch (selectedchesspiece->ChessPieceColorOutput())
	{
	case CHESSPIECECOLOR_WHITE:
		for (auto iter = m_BlackChesspieceList.begin(); iter != m_BlackChesspieceList.end(); iter++)
		{
			tmprect = { (*iter)->ChessPiecePositionOutput().x,(*iter)->ChessPiecePositionOutput().y,(*iter)->ChessPiecePositionOutput().x + CHESSPIECESIZE,(*iter)->ChessPiecePositionOutput().y + CHESSPIECESIZE };
			if (IntersectRect(&tmprect2, &lastmovedchesspiecerect, &tmprect) == true)
			{
				if (*iter == m_BlackChesspieceList[(m_BlackChesspieceList.size() - 1)])
				{
					m_BlackChesspieceList.pop_back();
					break;
				}
				else
				{
					iter = m_BlackChesspieceList.erase(iter);
					break;
				}
			}
		}
		break;
	case CHESSPIECECOLOR_BLACK:
		for (auto iter = m_WhiteChesspieceList.begin(); iter != m_WhiteChesspieceList.end(); iter++)
		{
			tmprect = { (*iter)->ChessPiecePositionOutput().x,(*iter)->ChessPiecePositionOutput().y,(*iter)->ChessPiecePositionOutput().x + CHESSPIECESIZE,(*iter)->ChessPiecePositionOutput().y + CHESSPIECESIZE };
			if (IntersectRect(&tmprect2, &lastmovedchesspiecerect, &tmprect) == true)
			{
				if (*iter == m_WhiteChesspieceList[(m_WhiteChesspieceList.size() - 1)])
				{
					m_WhiteChesspieceList.pop_back();
					break;
				}
				else
				{
					iter = m_WhiteChesspieceList.erase(iter);
					break;
				}
			}
		}
		break;
	}
}

void ChesspieceManager::ChesspiecePromotion(HDC hdc,Chesspiece*selectedchesspiece, CHESSPIECE chesspiece)
{
	Chesspiece*tmp;
	switch (chesspiece)
	{
	case CHESSPIECE_KNIGHT:
		tmp = new Knight;
		break;
	case CHESSPIECE_BISHOP:
		tmp = new Bishop;
		break;
	case CHESSPIECE_ROOK:
		tmp = new Rook;
		break;
	case CHESSPIECE_QUEEN:
		tmp = new Queen;
		break;
	}
	tmp->ChesspieceInit(hdc, selectedchesspiece->ChessPieceColorOutput(), selectedchesspiece->ChessPiecePositionOutput());
	ChesspieceDelete(selectedchesspiece);
	switch (tmp->ChessPieceColorOutput())
	{
	case CHESSPIECECOLOR_WHITE:
		m_WhiteChesspieceList.push_back(tmp);
		break;
	case CHESSPIECECOLOR_BLACK:
		m_BlackChesspieceList.push_back(tmp);
		break;
	}
}

void ChesspieceManager::ChesspieceDelete(Chesspiece*selectedchesspiece)
{
		switch (selectedchesspiece->ChessPieceColorOutput())
		{
		case CHESSPIECECOLOR_WHITE:
			for (auto iter = m_WhiteChesspieceList.begin(); iter != m_WhiteChesspieceList.end(); iter++)
			{
				if ((*iter)->ChessPiecePositionOutput().x == selectedchesspiece->ChessPiecePositionOutput().x && (*iter)->ChessPiecePositionOutput().y == selectedchesspiece->ChessPiecePositionOutput().y)
				{
					if (*iter == m_WhiteChesspieceList[(m_WhiteChesspieceList.size() - 1)])
					{
						m_WhiteChesspieceList.pop_back();
						break;
					}
					else
					{
						iter = m_WhiteChesspieceList.erase(iter);
						break;
					}
				}
			}
			break;
		case CHESSPIECECOLOR_BLACK:
			for (auto iter = m_BlackChesspieceList.begin(); iter != m_BlackChesspieceList.end(); iter++)
			{
				if ((*iter)->ChessPiecePositionOutput().x == selectedchesspiece->ChessPiecePositionOutput().x && (*iter)->ChessPiecePositionOutput().y == selectedchesspiece->ChessPiecePositionOutput().y)
				{
					if (*iter == m_BlackChesspieceList[(m_BlackChesspieceList.size() - 1)])
					{
						m_BlackChesspieceList.pop_back();
						break;
					}
					else
					{
						iter = m_BlackChesspieceList.erase(iter);
						break;
					}
				}
			}
			break;
		}
}

Chesspiece* ChesspieceManager::KingOutput(CHESSPIECECOLOR color)
{
	switch (color)
	{
	case CHESSPIECECOLOR_WHITE:
		for (auto iter = m_WhiteChesspieceList.begin(); iter != m_WhiteChesspieceList.end(); iter++)
		{
			if ((*iter)->ChessPieceOutput() == CHESSPIECE_KING)
				return *iter;
		}
		break;
	case CHESSPIECECOLOR_BLACK:
		for (auto iter = m_BlackChesspieceList.begin(); iter != m_BlackChesspieceList.end(); iter++)
		{
			if ((*iter)->ChessPieceOutput() == CHESSPIECE_KING)
				return *iter;
		}
		break;
	}
	return NULL;

}

ChesspieceManager::~ChesspieceManager()
{
	AllChesspieceDelete();
}
