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
	POINT m_BlockPos;
public:
	void BlockInit(HDC hdc, BLOCKCOLOR blockcolor, POINT pos);
	void BlockDraw(HDC hdc);
	void BlockPositionChange(POINT pos);
	Block();
	inline POINT BlockPositionOutput()
	{
		return m_BlockPos;
	}
	~Block();
};

