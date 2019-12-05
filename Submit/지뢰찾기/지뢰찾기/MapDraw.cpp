#include "MapDraw.h"

MapDraw::MapDraw()
{
}

void MapDraw::DrawMidText(string str, int x, int y)
{
	if (x > str.size() / 2)
		x -= str.size() / 2;
	gotoxy(x, y);
	cout << str;
	return;
}

void MapDraw::DrawPoint(string str, int x, int y)
{
	gotoxy(x * 2, y);
	cout << str;
	gotoxy(-1, -1);
	return;
}

void MapDraw::ErasePoint(int x, int y)
{
	gotoxy(x * 2, y);
	cout << "  ";
	gotoxy(-1, -1);
	return;
}

void MapDraw::MapSizeSet(int width, int height)
{
	char buf[256];
	sprintf(buf, "mode con: cols=%d lines=%d", width * 2, height+5);
	system(buf);
}

void MapDraw::GameMapDraw(int width, int height)
{
	for (int y = 0; y < (height); y++)
	{
		gotoxy(0,y);
		{
			for (int x = 0; x < width; x++)
			{
				if (y == 0 || y == (height-1) || x == 0 || x == (width - 1))
					cout << "▣";
				else
					cout << "■";
			}

		}
	}
	gotoxy(0, height+2);
	cout << "커서이동 : wasd" << endl;
	cout << "선택 : spacebar" << endl;
}


MapDraw::~MapDraw()
{
}
