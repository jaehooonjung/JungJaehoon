#pragma once
#include<Windows.h>
#include"resource.h"

class Card
{
private:
	HDC m_MemDC;
	HBITMAP m_pBitMap;
	HBITMAP m_pBitOld;
	SIZE m_size;
	int m_iBitmapName;
	int m_iStart_x;
	int m_iStart_y;
	bool m_bOpenFlag;
	bool m_bClearFlag;
public:
	void init(HDC hdc, HINSTANCE hInst, int bitmapname);
	void CardInfoSet(int start_x, int start_y);
	void CardDraw(HDC hdc, int x, int y ,int rate_x, int rate_y);
	Card();
	inline int SizeXOutput()
	{
		return m_size.cx;
	}
	inline int SizeYOutput()
	{
		return m_size.cy;
	}
	inline bool OpenFlagOutput()
	{
		return m_bOpenFlag;
	}
	~Card();
};

