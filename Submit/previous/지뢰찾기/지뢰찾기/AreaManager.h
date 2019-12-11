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

/*
enum 으로 한줄을 배열로 만든다
지뢰인지 일반영역인지 플래그를 만든다


*/