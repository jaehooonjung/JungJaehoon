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

void Area::CheckFlagChange()
{
	if (m_bCheckFlag == true)
		m_bCheckFlag = false;
	else
		m_bCheckFlag = true;
	
}

void Area::Area::HintSet(int Hint)
{
	switch (Hint)
	{
	case 1:
		m_strShape = "¨ç";
		break;
	case 2:
		m_strShape = "¨è";
		break;
	case 3:
		m_strShape = "¨é";
		break;
	case 4:
		m_strShape = "¨ê";
		break;
	case 5:
		m_strShape = "¨ë";
		break;
	case 6:
		m_strShape = "¨ì";
		break;
	case 7:
		m_strShape = "¨í";
		break;
	case 8:
		m_strShape = "¨î";
		break;
	default:
		m_strShape = "¡à";
		break;
	}
}

Area::~Area()
{
}
