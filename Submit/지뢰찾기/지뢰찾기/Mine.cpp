#include "Mine.h"



Mine::Mine()
{
}

void Mine::MinePositionSet(int x, int y)
{
	m_iMinePosition_X = x;
	m_iMinePosition_Y = y;
	m_MineStatus = MINESTATUS_MISSING;
}

bool Mine::MineCheck(int x, int y)
{
	if (m_iMinePosition_X == x && m_iMinePosition_Y == y)
		return true;
	else
		return false;
}

Mine::~Mine()
{
}
