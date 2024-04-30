
#include <C:\Users\User\Desktop\zadachi+push git\tiktactoe console vers\tiktactoe console vers\game.h>
int main()
{
	char reply;
	printf_s("Hello,player! Do u wanna play a tictactoe?\n\n");
	reply = _getch();
	while (reply != 'y' && reply != 'n')
	{
		printf_s("\nplease enter a valid reply (y/n):");
		reply = _getch();
	}
	int x_wins = 0, o_wins = 0, ties = 0;

	while (reply == 'y')
	{
		clearboard();
		char winner = play_and_get_winner();
		print_board();

		switch (winner)
		{
		case 'X':
			x_wins++;
			break;
		case '0':
			o_wins++;
			break;
		case 'D':
			ties++;
			break;
		}

		printf_s("\n\t*Winner statistic*\nPlayer X:");
		printf_s("%d", x_wins);
		printf_s(" Player 0:");
		printf_s("%d", o_wins);
		printf_s(" and Ties: ");
		printf_s("%d", ties);
		printf_s("\n\n");

		printf_s("\n would you like to play again? (y/n): ");
		reply = _getch();
		

	}


	return 0;
}
