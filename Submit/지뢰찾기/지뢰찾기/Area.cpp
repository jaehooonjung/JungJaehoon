#include "Area.h"



Area::Area()
{
}

void Area::AreaSet(int x, int y, bool MineFlag)
{
	m_ix = x;
	m_iy = y;
	m_bMineFlag = MineFlag;
	m_bCheckFlag = false;
}

void Area::ShapeChage(string shape)
{
	m_strShape = shape;
}
						/*
									void Area::HintSet(int Hint)
{
	switch (Hint)
	{
	case 1:
		m_strHint = "��";
		break;
	case 2:
		m_strHint = "��";
		break;
	case 3:
		m_strHint = "��";
		break;
	case 4:
		m_strHint = "��";
		break;
	case 5:
		m_strHint = "��";
		break;
	case 6:
		m_strHint = "��";
		break;
	case 7:
		m_strHint = "��";
		break;
	case 8:
		m_strHint = "��";
		break;
	default:
		m_strHint = "  ";
		break;
	}
	m_strHint = Hint;
}

						*/


Area::~Area()
{
}
