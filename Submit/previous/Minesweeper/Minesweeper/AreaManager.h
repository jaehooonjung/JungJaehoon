#pragma once
#include"MapDraw.h"

enum AREASTATE_MINE
{
	AREASTATE_MINE_CLEAR,
	AREASTATE_MINE_BURIED
};

enum AREASTATE_CHECK
{
	AREASTATE_CHECK_NO,
	AREASTATE_CHECK_YES
};

emum AREASTATE_BOCLK
{

}

struct Area
{
	int m_ix;
	int m_iy;
	string m_strShape;
	AREASTATE_MINE m_MineFlag;
	AREASTATE_CHECK m_CheckFlag;
};

class AreaManager
{
private:
	static AreaManager* m_hThis;
	vector<Area*>AreaList;
	MapDraw m_MapDraw;
public:
	static AreaManager* GetInstace()
	{
		if (m_hThis == NULL)
			m_hThis = new AreaManager;
		return m_hThis;
	}
	void AreaSet();
	string AreaShapeOutput(int x, int y);
	void AreaCheck(int x, int y, int width, int height);
	bool CheckFlagCheck(int width, int height);
	void DeleteAreaAll();
	AreaManager();
	~AreaManager();
};

