#include "MapDraw.h"

MapDraw* MapDraw::m_hThis = NULL;


MapDraw::MapDraw()
{
	MapSizeSet(WIDTH_DEFUALT, HEIGHT_DEFUALT);
}

void MapDraw::MapSizeSet(int width, int height)
{
	m_iWidth = width;
	m_iHeight = height;
	char buf[256];
	sprintf(buf, "mode con: cols=%d lines=%d", m_iWidth * 2, m_iHeight);
	system(buf);
}

void MapDraw::GameMapDraw()
{
	for (int y = 0; y < (m_iHeight-5); y++)
	{
		gotoxy(0,y);
		{
			for (int x = 0; x < m_iWidth; x++)
			{
				if (y == 0 || y == (m_iHeight - 6) || x == 0 || x == (m_iWidth - 1))
					cout << "▣";
				else
					cout << "■";
			}

		}
	}
	gotoxy(0, m_iHeight-3);
	cout << " 커서이동 : wasd   선택 : spacebar" << endl;
}


MapDraw::~MapDraw()
{
}
