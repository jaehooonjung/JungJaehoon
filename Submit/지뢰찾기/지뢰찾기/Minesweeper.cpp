#include "Minesweeper.h"



Minesweeper::Minesweeper()
{
	//�ܼ�â ũ�� ����

}

void Minesweeper::MinesweeperGameStart()
{
			 //���ڵ�ο�
}

void Minesweeper::MinesweeperMenu()
{
	int Select;

	while (1)
	{
		system("cls");
		cout << "\t===== ����ã�� =====" << endl;
		cout << "1. ���ӽ���" << endl;
		cout << "2. ���ӿɼ�" << endl;
		cout << "3. ��ŷ" << endl;
		cout << "4. ����" << endl;
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
