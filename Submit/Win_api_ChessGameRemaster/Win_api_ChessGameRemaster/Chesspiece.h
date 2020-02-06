#pragma once
#include"Mecro.h"

class Chesspiece
{
protected:
	HDC m_MemDC;
	HBITMAP m_phImage;
	HBITMAP m_phOldBitmap;
	SIZE m_size;
	CHESSPIECE m_ChessPiece;
	CHESSPIECECOLOR m_ChessPieceColor;
	POINT m_ChesspiecePos;
	POINT m_destinationPos;
	vector<POINT>m_PointList;
public:
	void ChesspieceInit(HDC hdc, CHESSPIECECOLOR chesspiececolor, POINT pos);
	virtual string ChessPieceSet(CHESSPIECECOLOR chesspiececolor) = 0;
	void ChessPieceColorSet(CHESSPIECECOLOR chesspiececolor);
	void ChessPiecePositionSet(POINT pos);
	void ChessPieceDraw(HDC hdc);
	bool ChessPiecePositionCheck(POINT pos);
	void ChessPiecePointListInput(POINT pos);
	bool ChessPieceMovePosSet(POINT pos);
	virtual bool ChessPieceMove();
	virtual bool PromotionCheck() { return false; };
	void PointListClear();
	void DeleteBitmap();
	bool CheckCheck(POINT pos);
	Chesspiece();
	inline CHESSPIECE ChessPieceOutput()
	{
		return m_ChessPiece;
	}
	inline POINT ChessPiecePositionOutput()
	{
		return m_ChesspiecePos;
	}
	inline vector<POINT>PointListOutput()
	{
		return m_PointList;
	}
	inline CHESSPIECECOLOR ChessPieceColorOutput()
	{
		return m_ChessPieceColor;
	}
	inline POINT DestinationPosOutput()
	{
		return m_destinationPos;
	}
	~Chesspiece();
};

class Pawn :public Chesspiece
{
public:
	string ChessPieceSet(CHESSPIECECOLOR chesspiececolor);
	bool PromotionCheck();
	Pawn() {m_PointList.reserve(3);};
	~Pawn() { DeleteBitmap(); };
};

class Knight :public Chesspiece
{
public:
	string ChessPieceSet(CHESSPIECECOLOR chesspiececolor);
	bool ChessPieceMove();
	Knight() { m_PointList.reserve(8); };
	~Knight() { DeleteBitmap(); };
};

class Bishop :public Chesspiece
{
public:
	string ChessPieceSet(CHESSPIECECOLOR chesspiececolor);
	Bishop() { m_PointList.reserve(32); };
	~Bishop() { DeleteBitmap(); };
};

class Rook :public Chesspiece
{
public:
	string ChessPieceSet(CHESSPIECECOLOR chesspiececolor);
	Rook() { m_PointList.reserve(32); };
	~Rook() { DeleteBitmap(); };
};

class Queen :public Chesspiece
{
public:
	string ChessPieceSet(CHESSPIECECOLOR chesspiececolor);
	Queen() { m_PointList.reserve(56); };
	~Queen() { DeleteBitmap(); };
};

class King :public Chesspiece
{
public:
	string ChessPieceSet(CHESSPIECECOLOR chesspiececolor);
	King() { m_PointList.reserve(8); };
	~King() { DeleteBitmap();};
};

