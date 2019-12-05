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

void Mine::HintSet(int Hint)
{
	switch (Hint)
	{
	case 1:
		m_strHint = "¨ç";
		break;
	case 2:
		m_strHint = "¨è";
		break;
	case 3:
		m_strHint = "¨é";
		break;
	case 4:
		m_strHint = "¨ê";
		break;
	case 5:
		m_strHint = "¨ë";
		break;
	case 6:
		m_strHint = "¨ì";
		break;
	case 7:
		m_strHint = "¨í";
		break;
	case 8:
		m_strHint = "¨î";
		break;
	default:
		m_strHint = "  ";
		break;
	}
	m_strHint = Hint;
}


Mine::~Mine()
{
}
