#include<stdio.h>
#include<Windows.h>
void main()
{

	int a, b,c, sum;
	float avg;

	scanf("%d%d%d", &a, &b, &c);

	sum = (a + b + c);
	avg = (float)(sum / 3);

	if (avg >= 90)
		printf("A");
	else if (avg >= 80)
		printf("B");
	else if (avg >= 70)
		printf("C");
	else if (avg >= 60)
		printf("D");
	else
		printf("F");

	system("pause");
}
