#pragma once
#include<Windows.h>
#include<time.h>
using namespace std;
class Card
{
private:
	HDC		m_MemDC;
	HBITMAP	m_pBitMap;
	HBITMAP m_pBitOld;
	SIZE	m_size;
	int m_iBitmapName;
	int m_iCardPosition_x;
	int m_iCardPosition_y;
	bool m_bOpenFlag;
	bool m_bClearFlag;
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
	inline bool OpenFlagOutput()
	{
		return m_bOpenFlag;
	}
	inline int BitmapNameOutput()
	{
		return m_iBitmapName;
	}
	~Card();
};

