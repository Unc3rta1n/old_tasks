#include <C:\Users\User\Desktop\zadachi+push git\tiktactoe console vers\tiktactoe console vers\game.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
void clearscreen()
{
	system("cls");
}


void clearboard()
{
	for (int i = 0; i < 9; i++)
	{
		board[i] = '-';
	}

}


bool has_wonQ(char player)
{
	int wins[][3] = { {0,1,2},
		{3,4,5},
		{6,7,8},
		{0,3,6},
		{1,4,7},
		{2,5,8},
		{0,4,8},
		{2,4,6}
	};

	for (int i = 0; i < 8; i++)
	{
		int count = 0;
		for (int j = 0; j < 3; j++)
		{
			if (board[wins[i][j]] == player)
				count++;
		}
		if (count == 3)
		{
			return true;
		}
	}
	return false;
}


void print_board()
{
	printf_s("Game board\n");
	printf_s("-");
	printf_s("%c", board[6]);
	printf_s("-|-");
	printf_s("%c", board[7]);
	printf_s("-|-");
	printf_s("%c\n", board[8]);
	printf_s("-");
	printf_s("%c", board[3]);
	printf_s("-|-");
	printf_s("%c", board[4]);
	printf_s("-|-");
	printf_s("%c\n", board[5]);
	printf_s("-");
	printf_s("%c", board[0]);
	printf_s("-|-");
	printf_s("%c", board[1]);
	printf_s("-|-");
	printf_s("%c\n", board[2]);

}


int get_move()
{
	printf_s("\nmove menu: \n");
	printf_s("-7-|-8-|-9-\n");
	printf_s("-4-|-5-|-6-\n");
	printf_s("-1-|-2-|-3-\n");


	print_board("");




	printf_s("enter the cell:");
	int move;
	scanf_s("%d", &move);

	while (move > 9 || move < 1 || board[move - 1] != '-')
	{
		printf_s("enter the cell(1-9 range):\n");
		scanf_s("%d", &move);

	}

	return move;
}


char play_and_get_winner()
{
	int turn = 1;

	while (!has_wonQ('X') && !has_wonQ('0'))
	{
		clearscreen();

		int move = get_move();

		clearscreen();
		if (turn % 2 == 1)
		{
			board[move - 1] = 'X';
			if (has_wonQ('X'))
			{
				printf_s("X,Congrats, u win!\n");
				return 'X';
			}

		}
		else
		{
			board[move - 1] = '0';
			if (has_wonQ('0'))
			{
				printf_s("O,Congrats, u win!\n");
				return '0';
			}
		}
		turn++;
		if (turn == 10)
		{
			printf_s("Draw!\n");
			return 'D';
		}
	}
}