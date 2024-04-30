#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Field.h"
int main(void)
{
	srand(time(0));
	char c = { 0 };
	c = getchar();
	while (1) {
		if (c == 'y')
		{
			zeroedfield(field);
			choose_2walls = rand() % 2;
			if (choose_2walls == 1) printf_s("right wall to left wall\n");
			else printf_s("lower wall to upper wall\n");
			random_path(choose_2walls);
			printfield(field);
			system("pause");
			system("cls");
		}
		else break;
	}
	return 0;
}