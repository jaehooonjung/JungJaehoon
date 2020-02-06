#pragma once
#include "Block.h"

class BlockManager
{
private:
	vector<Block*> BlockList;
	Block*m_MarkingBlock;
public:
	void BlockInit(HDC hdc);
	void BlockDelete();
	void BlockDraw(HDC hdc);
	void MarkingBlockInit(HDC hdc);
	void MarkingBlockDraw(HDC hdc, POINT pos);
	bool OnTheBlockCheck(POINT pos);
	BlockManager();
	~BlockManager();
};
