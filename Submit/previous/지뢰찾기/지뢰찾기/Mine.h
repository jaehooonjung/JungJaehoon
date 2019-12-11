#pragma once
#include"Mecro.h"

enum MINESTATUS
{
	MINESTATUS_MISSING,
	MINESTATUS_FIND
};

class Mine
{
private:
	int m_iMinePosition_X;
	int m_iMinePosition_Y;
	string m_strHint;
	MINESTATUS m_MineStatus;
public:
	void MinePositionSet(int x, int y);
	bool MineCheck(int x, int y);
	Mine();
	inline MINESTATUS MineStatusOutput()
	{
		return m_MineStatus;
	}
	inline int Mine_X_Position_Output()
	{
		return m_iMinePosition_X;
	}
	inline int Mine_Y_Position_Output()
	{
		return m_iMinePosition_Y;
	}
	~Mine();
};

