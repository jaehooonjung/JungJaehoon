#include "Car.h"



Car::Car()
{
}

void Car::CarInformationSetting(int CarNum, int CarXpos, int CarYpos)
{
	m_bDrawStatus = DRAWFLAG_YES;
	m_iCarNumber = CarNum;
	m_iXpos = CarXpos;
	m_iYpos = CarYpos;
	m_NewNode = NULL;
}

void Car::NewNodeSetting(Car*Tmp)
{
	m_NewNode = Tmp;
}

void Car::CarDraw()
{

	if (m_bDrawStatus == DRAWFLAG_NO)
		return;
	MapDrawManager.DrawPoint(" ¦£¦¡¦¡¦¤", m_iXpos, m_iYpos);
	MapDrawManager.DrawPoint("¦¦¥Ï¦¡¥Ï¦¥", m_iXpos, m_iYpos +1);
}

void Car::CarErase()
{
	MapDrawManager.EraseText(" ¦£¦¡¦¡¦¤", m_iXpos*2, m_iYpos);
	MapDrawManager.EraseText("¦¦¥Ï¦¡¥Ï¦¥", m_iXpos*2, m_iYpos + 1);
}


void Car::CarMove()
{
	CarErase();
	if (m_bDrawStatus == DRAWFLAG_NO)
		return;
	m_iXpos--;
	if(m_iXpos == 1)
		m_bDrawStatus = DRAWFLAG_NO;
}


Car::~Car()
{
}
