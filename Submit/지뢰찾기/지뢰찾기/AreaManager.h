#pragma once
#include"Area.h"
#include"MineManager.h"
#include"MapDraw.h"
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
	void AreaSet(int width, int height);
	string AreaShapeOutput(int x, int y);
	void AreaCheck(int x, int y, int width, int height);
	bool CheckFlagCheck(int width, int height);
	void DeleteAreaAll();
	AreaManager();
	~AreaManager();
};

