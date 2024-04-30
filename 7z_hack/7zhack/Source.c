#include <stdio.h>
#include <conio.h>
#include<Windows.h>
#include <stdlib.h>
#include < string.h >
int main(void)
{
	int c[8];
	char result[100];
	for (int i = 0; i <= 9; i++)
	{
		if (i == 0) c[0] = '0';
		c[0] = i;
		for (int j = 1; j <= 9; j++)
		{
			c[1] = j;
			for (int k = 0; k <= 9; k++)
			{
				if (k == 0) c[2] = '0';
				c[2] = k;
				for (int l = 1; l <= 9; l++)
				{
					c[3] = l;
					c[4] = 1;
					c[5] = 9;
					c[6] = 9;
					c[7] = 1;


					char command[100] = "7z e -p";
					int p = 0;
					for (int i = 7; i <= 14; i++)
					{
						command[i] = c[p] + '0';

						p++;

					}
					command[15] = ' ';
					command[16] = '1';
					command[17] = '.';
					command[18] = '7';
					command[19] = 'z';
					command[20] = '\0';
					system(command);

				}
			}
		}
	}

}
