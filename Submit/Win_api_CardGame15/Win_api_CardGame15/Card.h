#pragma once
#include<Windows.h>
#include<time.h>
#include"resource.h"
using namespace std;

#define CARDSIZE_WIDTH_DEFAULT 200
#define CARDSIZE_HEIGHT_DEFAULT 250

enum CARDSTATUS
{
	CARDSTATUS_UNKNOWN,
	CARDSTATUS_OPEN,
	CARDSTATUS_CLEAR
};

class Card
{
private:
	HDC m_MemDC;
	HBITMAP m_pBitMap;
	HBITMAP m_pBitOld;
	SIZE m_size;
	int m_iBitmapName;
	int m_iCardPosition_x;
	int m_iCardPosition_y;
	CARDSTATUS m_CardStatus;
public:
	void init(HDC hdc, HINSTANCE hInst, int bitmapname);
	void CardInfoSet(int CardPosition_x, int CardPosition_y);
	void CardDraw(HDC hdc);
	Card();
	inline int CardPosition_x_Output()
	{
		return m_iCardPosition_x;
	}
	inline int CardPosition_y_Output()
	{
		return m_iCardPosition_y;
	}
	inline int SizeXOutput()
	{
		return m_size.cx;
	}
	inline int SizeYOutput()
	{
		return m_size.cy;
	}
	inline int BitmapNameOutput()
	{
		return m_iBitmapName;
	}
	inline void CardStatusChangeToUnknown()
	{
		m_CardStatus = CARDSTATUS_UNKNOWN;
	}
	inline void CardStatusChangeToOpen()
	{
		m_CardStatus = CARDSTATUS_OPEN;
	}
	inline void CardStatusChangeToClear()
	{
		m_CardStatus = CARDSTATUS_CLEAR;
	}
	inline CARDSTATUS CARDSTATUSOutput()
	{
		return m_CardStatus;
	}
	~Card();
};

