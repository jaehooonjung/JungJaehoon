#pragma once
#include "Chesspiece.h"

class ChesspieceManager
{
private:
	vector<Chesspiece> m_WhiteChesspiece;
	vector<Chesspiece> m_BlackChesspiece;
public:
	void ChesspieceManagerinit();
	ChesspieceManager();
	~ChesspieceManager();
};

