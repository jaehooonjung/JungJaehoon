#pragma once
#include"Mecro.h"
class Area
{
private:
	int m_ix;
	int m_iy;
	string m_strShape;
	bool m_bMineFlag;
	bool m_bCheckFlag;
public:
	void AreaSet(int x, int y, bool MineFlag);
	void ShapeChage(string shape);
	void CheckFlagChange();
	void HintSet(int Hint);
	Area();
	inline bool CheckFlagOutput()
	{
		return m_bCheckFlag;
	}
	inline int X_Pos_Output()
	{
		return m_ix;
	}
	inline int Y_Pos_Output()
	{
		return m_iy;
	}
	inline string ShapeOutput()
	{
		return m_strShape;
	}
	~Area();
};

