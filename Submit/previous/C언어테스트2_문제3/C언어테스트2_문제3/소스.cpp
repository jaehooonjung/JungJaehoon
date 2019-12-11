#include<stdio.h>
#include<windows.h>
void main()

{
	int sum = 0;

	for (int i = 1; i <= 1000; i++)
	{
		if (i % 3 == 0)
		{
			if (i % 5 == 0)
				sum += i;
			continue;
		}
		sum += i;
	}
	system("pause");
}