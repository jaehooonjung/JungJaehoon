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

void MapDraw::TextDraw(string str, int x, int y)
{
	gotoxy(x, y);
	cout << str;
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

void MapDraw::EraseText(string Text, int x, int y)
{
	int TextLength = Text.length();
	string Eraser = { "" };
	for (int i = 0; i < TextLength; i++)
	{
		Eraser += " ";
	}
	gotoxy(x, y);
	cout << Eraser;
	return;

}

int MapDraw::MenuSelectCursor(int MenuLen, int AddCol, int x, int y)
{
	int Select = 1;
	RED
		DrawPoint("▷", x, y);
	ORIGINAL
		while (1)
		{
			switch (getch())
			{
			case UP:
				if (Select - 1 >= 1)
				{
					ErasePoint(x, y);
					y -= AddCol;
					Select--;
				}
				break;
			case DOWN:
				if (Select + 1 <= MenuLen)
				{
					ErasePoint(x, y);
					y += AddCol;
					Select++;
				}
				break;
			case ENTER:
				return Select;
			}
			RED
				DrawPoint("▷", x, y);
			ORIGINAL
		}
}

void MapDraw::MenuDraw()
{
	DrawMidText("톨게이트", WIDTH, HEIGHT*0.3f);
	DrawMidText("1. 시작", WIDTH, HEIGHT*0.5f);
	DrawMidText("2. 종료", WIDTH, HEIGHT*0.7f);
}

void MapDraw::GateDraw()
{
	system("cls");
	for (int ypos = 0; ypos < GATESIZE; ypos++)
	{
		for (int xpos = 0; xpos < CARXPOSDEFAULT; xpos++)
		{
			if( (ypos % 5) ==  0 && xpos <= 3)
				DrawPoint("▥", xpos, ypos);
			if(ypos == 1 || ypos == 4)
				DrawPoint("▣", xpos, ypos);
		}
	}

}



MapDraw::~MapDraw()
{
}
