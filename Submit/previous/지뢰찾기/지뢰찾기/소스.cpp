#include"Minesweeper.h"

void main()
{
	//_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	//_crtBreakAlloc = 1720;


	srand((unsigned)time(NULL));
	Minesweeper MinesweeperManager;
	MinesweeperManager.MinesweeperMenu();
}
