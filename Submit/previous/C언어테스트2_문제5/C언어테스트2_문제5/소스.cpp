#include<stdio.h>
#include<windows.h>
#include<time.h>

void main()
{
	srand((unsigned)time(NULL));
	int RamdomNum, tmp;
	RamdomNum = (rand() % 100);
	while (1)
	{
		scanf("%d", &tmp);
		system("cls");
		if (tmp < RamdomNum)
		{
			printf("UP!\n");
		}
		else if (tmp > RamdomNum)
		{
			printf("Down!\n");
		}
		else
			break;
	}
	printf("정답\n게임종료");
	system("pause");
}