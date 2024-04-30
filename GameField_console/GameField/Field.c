#include "Field.h"

void zeroedfield(char field[width][height])
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			field[i][j] = '0';
		}
	}
}

void printfield(char field[width][height])
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (field[i][j] == '0') field[i][j] = '#';
			if (field[i][j] == 'g') field[i][j] = '_';
			printf_s("%c ", field[i][j]);
		}
		printf_s("\n");
	}
}

void random_path(int choose_2walls)
{
	if (choose_2walls == 0) {
		startpos = rand() % width;
		field[width - 1][startpos] = 'g';
	}
	else
	{
		startpos = rand() % height;
		field[startpos][height - 1] = 'g';
	}
	if (choose_2walls == 0)
	{
		int i = width - 2;
		int j = startpos;
		field[i][j] = 'g';
		while (i > 0)
		{
			int choose_side = rand() % 4;
			if (choose_side == up)
			{
				i--;
				field[i][j] = 'g';
			}
			else if (choose_side == right)
			{
				if (j + 1 < height && field[i][j + 1] != 'g' && field[i + 1][j + 1] != 'g')
				{
					j++;
					field[i][j] = 'g';
				}
			}
			else if (choose_side == left)
			{
				if (j - 1 > 0 && field[i + 1][j - 1] != 'g' && field[i][j - 1] != 'g')
				{
					j--;
					field[i][j] = 'g';
				}
			}
			else if (choose_side == down)
			{
				if (i + 1 < width && field[i + 1][j] != 'g' && field[i + 1][j - 1] != 'g' && field[i + 1][j + 1] != 'g')
				{
					i++;
					field[i][j] = 'g';
				}
			}


		}
	}
	else
	{
		int i = startpos;
		int j = height - 2;
		field[i][j] = 'g';
		while (j > 0)
		{
			int choose_side = rand() % 4;

			if (choose_side == up)
			{
				if (i - 1 > 0 && field[i - 1][j] != 'g' && field[i - 1][j - 1] != 'g')
				{
					i--;
					field[i][j] = 'g';
				}

			}
			else if (choose_side == right)
			{
				if (j + 1 < width && field[i][j + 1] != 'g' && field[i - 1][j + 1] != 'g' && field[i + 1][j + 1] != 'g')
				{
					j++;
					field[i][j] = 'g';
				}
			}
			else if (choose_side == left)
			{
				j--;
				field[i][j] = 'g';

			}
			else if (choose_side == down)
			{
				if (i + 1 < width && field[i + 1][j] != 'g' && field[i + 1][j + 1] != 'g')
				{
					i++;
					field[i][j] = 'g';
				}
			}
		}
	}
}