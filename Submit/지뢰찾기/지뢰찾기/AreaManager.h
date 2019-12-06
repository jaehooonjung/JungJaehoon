#pragma once
#include"Area.h"
#include"MineManager.h"
class AreaManager
{
private:
	static AreaManager* m_hThis;
	vector<Area*>AreaList;
public:
	static AreaManager* GetInstace()
	{
		if (m_hThis == NULL)
			m_hThis = new AreaManager;
		return m_hThis;
	}
	void AreaSet(int width, int height);
	string AreaShapeOutput(int x, int y);
	string AreaCheck(int x, int y);
	void DeleteAreaAll();
	AreaManager();
	~AreaManager();
};

