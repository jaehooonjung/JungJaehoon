#pragma once
#include"Mecro.h"
class Block
{
private:
	HDC m_MemDC;
	HBITMAP m_phImage;
	HBITMAP m_phOldBitmap;
	SIZE m_size;
	BLOCKCOLOR m_BlockColor;
	Position m_BlockPos;
public:
	void BlockInit(HDC hdc, BLOCKCOLOR blockcolor, int x, int y);
	void BlockDraw(HDC hdc);
	Block();
	~Block();
};

