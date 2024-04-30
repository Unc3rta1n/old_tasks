#include <stdio.h>
#include <time.h>
#include "check_params.h"

int main(int argc, char** argv) {
	srand(time(NULL));
	init_options();
	if (checker(argc, argv) != 0)
	{
		printf("\nProgram ends with code -1\n");
		return -1;
	}
	free(op.alph.alphabet);
	return 0;
}
