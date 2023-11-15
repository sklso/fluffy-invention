#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int x, hun, ten, ind;
	scanf("%d", &x);
	hun = x / 100;
	ten = (x - hun * 100) / 10;
	ind = x % 10;
	if (x >= 100 && x <= 999)
	{
		if (x == hun * hun * hun + ten * ten * ten + ind * ind * ind)
		{
			printf("Yes");
		}
		else
			printf("No");
	}
	else
		return 0;
}