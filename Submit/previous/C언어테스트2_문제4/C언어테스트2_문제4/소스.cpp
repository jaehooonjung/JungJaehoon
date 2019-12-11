#include<stdio.h>
#include<windows.h>
void main()
{
	int sum = 0, tmp;

	while (1)
	{
		system("cls");
		printf("현재값 : %d", sum);
		printf("\n입력 >>>");
		scanf("%d", &tmp);
		sum += tmp;
		if (tmp == 0)
			break;
	}

}
