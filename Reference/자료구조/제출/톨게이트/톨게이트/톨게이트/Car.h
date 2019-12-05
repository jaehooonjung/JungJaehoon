#pragma once
#include"MapDraw.h"
enum DRAWFLAG
{
	DRAWFLAG_NO,
	DRAWFLAG_YES

};

class Car
{
private:
	int m_iCarNumber;
	int m_iXpos;
	int m_iYpos;
	bool m_bDrawStatus;
	Car* m_NewNode;
	MapDraw MapDrawManager;
public:
	void CarInformationSetting(int CarNum, int CarXpos, int CarYpos);
	void NewNodeSetting(Car*Tmp);
	void CarDraw();
	void CarErase();
	void CarMove();
	Car();
	inline Car*NewNodeNullCheck()
	{
		return m_NewNode;
	}
	inline int CarNumber()
	{
		return m_iCarNumber;
	}
	~Car();
};

