#pragma once
#include "Chesspiece.h"

class ChesspieceManager
{
private:
	vector<Chesspiece*> m_WhiteChesspieceList;
	vector<Chesspiece*> m_BlackChesspieceList;
public:
	void ChesspieceManagerInit(HDC hdc);
	void ChesspieceCreate(HDC hdc, CHESSPIECE chesspiece);
	void AllChesspieceDraw(HDC hdc);
	void AllChesspieceDelete();
	Chesspiece* ChesspieceSelect(GAMESTATE gamestate, POINT pos);
	void ChesspieceRoadSetting(Chesspiece*selectedchesspiece);
	bool ChesspieceCheckSameColor(POINT pos, CHESSPIECECOLOR chesspiececolor);
	bool ChesspieceCheckAnotherColor(POINT pos, CHESSPIECECOLOR chesspiececolor);
	void RoadCheckUpperLeft(int length, Chesspiece*selectedchesspiece);
	void RoadCheckTop(int length, Chesspiece*selectedchesspiece);
	void RoadCheckUpperRight(int length, Chesspiece*selectedchesspiece);
	void RoadCheckLeft(int length, Chesspiece*selectedchesspiece);
	void RoadCheckRight(int length, Chesspiece*selectedchesspiece);
	void RoadCheckLowerLeft(int length, Chesspiece*selectedchesspiece);
	void RoadCheckBottom(int length, Chesspiece*selectedchesspiece);
	void RoadCheckLowerRight(int length, Chesspiece*selectedchesspiece);
	void RoadCheckKnight(Chesspiece*selectedchesspiece);
	void RoadCheckPawn(int length, Chesspiece*selectedchesspiece);
	void ChesspieceUpdate(Chesspiece*selectedchesspiece);
	void ChesspiecePromotion(HDC hdc, Chesspiece*selectedchesspiece, CHESSPIECE chesspiece);
	void ChesspieceDelete(Chesspiece*selectedchesspiece);
	Chesspiece* KingOutput(CHESSPIECECOLOR color);
	ChesspieceManager();
	~ChesspieceManager();
};

