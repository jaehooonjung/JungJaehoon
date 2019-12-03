#include "Minesweeper.h"



Minesweeper::Minesweeper()
{
	//콘솔창 크기 조절

}

void Minesweeper::MinesweeperGameStart()
{
			 //상자드로우
}

void Minesweeper::MinesweeperMenu()
{
	int Select;

	while (1)
	{
		system("cls");
		cout << "\t===== 지뢰찾기 =====" << endl;
		cout << "1. 게임시작" << endl;
		cout << "2. 게임옵션" << endl;
		cout << "3. 랭킹" << endl;
		cout << "4. 종료" << endl;
		cin >> Select;
		switch (Select)
		{
		case 1:
			MapDraw::GetInstance()->GameMapDraw();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			return;
			
		}
		system("pause");
	}

}

Minesweeper::~Minesweeper()
{
}
