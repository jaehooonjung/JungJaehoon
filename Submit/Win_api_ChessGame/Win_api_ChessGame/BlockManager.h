#pragma once
#include "Block.h"

class BlockManager
{
private:
	vector<Block*> BlockList;
public:
	void BlockInit(HDC hdc);
	void BlockDelete();
	void BlockDraw(HDC hdc);
	BlockManager();
	~BlockManager();
};

