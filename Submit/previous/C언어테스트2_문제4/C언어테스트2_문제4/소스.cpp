#include<stdio.h>
#include<windows.h>
void main()
{
	int sum = 0, tmp;

	while (1)
	{
		system("cls");
		printf("���簪 : %d", sum);
		printf("\n�Է� >>>");
		scanf("%d", &tmp);
		sum += tmp;
		if (tmp == 0)
			break;
	}

}
