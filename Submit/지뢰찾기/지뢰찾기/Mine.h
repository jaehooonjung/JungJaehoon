#pragma once
#include"Mecro.h"
class Mine
{
private:
	int m_iMinePosition_X;
	int m_iMinePosition_Y;
public:
	void MinePositionSet(int x, int y);
	bool MineCheck(int x, int y);
	Mine();
	~Mine();
};

