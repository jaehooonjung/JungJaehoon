#include<stdio.h>
#include<Windows.h>
void main()

{

	int a, b;
	printf("�� ���� �Է��ϼ��� : ");
	scanf("%d%d", &a, &b);

	if (a >= b)
	{
		if (a % 2 == 0)
			printf("%d", a);
	}
	else
	{
		if (b % 2 == 0)
			printf("%d", b);
	}
	system("pause");
}