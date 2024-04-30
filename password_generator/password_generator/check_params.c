#include "check_params.h"
void init_options()
{
	op.def_alph.C = false;
	op.def_alph.a = false;
	op.def_alph.A = false;
	op.def_alph.D = false;
	op.def_alph.S = false;
	op.length_params.m1 = false;
	op.length_params.m2 = false;
	op.length_params.n = false;
	op.alph.a = false;
	op.count.c = false;
	op.alph.a = false;
	op.length_params.len_m1 = 0;
	op.length_params.len_m2 = 0;
	op.length_params.len_n = 0;
	op.length_params.n = 0;
	op.count.c_count = 1;

}
int is_digits(char var)
{
	if (var == '0' || var == '1' || var == '2' || var == '3' || var == '4' ||
		var == '5' || var == '6' || var == '7' || var == '8' || var == '9')
		return 0;
	else
		return -1;
}


int check_options(int argc, char** argv)
{
	int j = 0;
	if (argv[1] == NULL)
	{
		printf("\nPassed nothing");
		return -1;
	}
	for (int i = 1; i < argc; i++)
	{
		j = 0;
		if (strcmp(argv[i], "-m1") == 0)
		{
			while (1)
			{
				if (op.length_params.m1 == true)
				{
					printf("\n'-m1' option has already been checked\n");
					return -1;
				}
				if (i + 1 < argc && argv[i + 1] != NULL)
				{
					if (argv[i + 1][j] == '\0')
						break;
					if (is_digits(argv[i + 1][j]) == 0) j++;
					else
					{
						printf("\n Incorrect arguments in '-m1' option\n");
						return -1;
					}
				}
				else
				{
					printf("\nEmpty option -m1\n");
					return -1;
				}
			}
			op.length_params.m1 = true;
			op.length_params.len_m1 = atoi(argv[i + 1]);
			continue;
		}
		if (strcmp(argv[i], "-m2") == 0)
		{
			while (1)
			{
				if (op.length_params.m2 == true)
				{
					printf("\n'-m2' option has already been checked\n");
					return -1;
				}
				if (i + 1 < argc && argv[i + 1] != NULL)
				{
					if (argv[i + 1][j] == '\0')
						break;
					if (is_digits(argv[i + 1][j]) == 0) j++;
					else
					{
						printf("\nIncorrect arguments in '-m2' option\n");
						return -1;
					}
				}
				else
				{
					printf("\nEmpty option -m2\n");
					return -1;
				}
			}
			op.length_params.m2 = true;
			op.length_params.len_m2 = atoi(argv[i + 1]);
			continue;
		}

		if (strcmp(argv[i], "-n") == 0)
		{
			while (1)
			{
				if (op.length_params.n == true)
				{
					printf("\n'-n' option has already been checked\n");
					return -1;
				}
				if (i + 1 < argc && argv[i + 1] != NULL)
				{
					if (argv[i + 1][j] == '\0')
						break;
					if (is_digits(argv[i + 1][j]) == 0) j++;
					else
					{
						printf("\n Incorrect arguments in '-n' option\n");
						return -1;
					}
				}
				else
				{
					printf("\nEmpty option -n\n");
					return -1;
				}

			}
			op.length_params.n = true;
			op.length_params.len_n = atoi(argv[i + 1]);
			continue;
		}

		if (strcmp(argv[i], "-c") == 0)
		{
			while (1)
			{
				if (op.count.c == true)
				{
					printf("\n'-c' option has already been checked\n");
					return -1;
				}

				if (i + 1 < argc && argv[i + 1] != NULL)
				{
					if (argv[i + 1][j] == '\0')
						break;
					if (is_digits(argv[i + 1][j]) == 0) j++;
					else
					{
						printf("\nIncorrect arguments in '-c' option\n");
						return -1;
					}
				}
				else
				{
					printf("\nEmpty option '-c'\n");
					return -1;
				}
			}
			op.count.c = true;
			op.count.c_count = atoi(argv[i + 1]);
			continue;
		}

		if (strcmp(argv[i], "-a") == 0)
		{
			if (op.alph.a == true)
			{
				printf("\n'-a' option has already been checked\n");
				return -1;
			}
			if (i + 1 < argc && argv[i + 1] != NULL)
			{
				if (check_a_option(&argv[i + 1][j]) == 0)
					op.alph.a = true;
				else return -1;
			}
			else 
			{
				printf("\nEmpty option '-a'\n");
				return -1;
			}
			i++;
			continue;
		}

		if (strcmp(argv[i], "-C") == 0)
		{
			if (op.def_alph.C == true)
			{
				printf("\n'-C' option has already been checked\n");
				return -1;
			}
			if (i + 1 < argc && argv[i + 1] != NULL)
			{
				if (check_C_option(&argv[i + 1][j]) == 0)
					op.def_alph.C = true;
				else return -1;
			}
			else
			{
				printf("\nEmpty option '-C'\n");
				return -1;
			}
			continue;
		}
	}

	return 0;
}

int check_a_option(char* argv)
{
	char* alph = { "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!#$'()-*+,./:;=?@[]^_`{}" };
	int j = 0, it = 0;

	while (argv[j] != '\0')
	{
		j++;
	}

	op.alph.alphabet = (char*)malloc((j + 1) * sizeof(char));
	op.alph.alphabet[j] = '\0';

	for (int i = 0; i < j; i++)
	{
		for (int _i = 0; _i < strlen(alph); _i++)
		{
			if (argv[i] == alph[_i])
			{
				op.alph.alphabet[it] = alph[_i];
				it++;
				break;
			}
			else if (_i == strlen(alph)-1)
			{
				printf("\nIncorrect symbols in option '-a'\n");
				return -1;
			}
		}
	}
	return 0;
}


int check_C_option(char* argv)
{
	int j = 0;

	while (argv[j] != '\0')
	{
		j++;
	}

	if (j > 4)
	{
		printf("\nInvalid numbers of parameteres in option '-C'\n");
		return -1;
	}

	for (int i = 0; i < j; i++)
	{
		if (argv[i] == 'A')
		{
			if (op.def_alph.A)
			{
				printf("\nRepeated parameter 'A' encountered\n");
				return -1;
			}
			else op.def_alph.A = true;
		}
		else if (argv[i] == 'a')
		{
			if (op.def_alph.a)
			{
				printf("\nRepeated parameter 'a' encountered\n");
				return -1;
			}
			else op.def_alph.a = true;
		}
		else if (argv[i] == 'D')
		{
			if (op.def_alph.D)
			{
				printf("\nRepeated parameter 'D' encountered\n");
				return -1;
			}
			else op.def_alph.D = true;
		}
		else if (argv[i] == 'S')
		{
			if (op.def_alph.S)
			{
				printf("\nERROR! Repeated parameter 'S' encountered\n");
				return -1;
			}
			else op.def_alph.S = true;
		}
		else
		{
			printf("\nERROR! Incorrect arguments in the '-C' option\n");
			return -1;
		}
	}
	return 0;
}

int check_conflict_options()
{
	if (op.alph.a == false && op.length_params.m1 == false && op.length_params.m2 == false && op.length_params.n == false && op.count.c == false && op.def_alph.C == false && op.alph.a == false)
	{
		printf("\nPassed nothing, or inappropriate parameters\n");
		return -1;
	}

	if ((op.length_params.m1 && op.length_params.len_m2 == 0) || (op.length_params.len_m1 == 0 && op.length_params.m2))
	{
		printf("\nIncorrect option paire '-m1' and '-m2'!\n");
		return -1;
	}

	if (op.length_params.m1 && op.length_params.m2 && op.length_params.n)
	{
		printf("\nIncorrect option paire '-m1','-m2' and '-n'\n");
		return -1;
	}

	if ((op.length_params.len_m1 != 0 || op.length_params.len_m2 != 0) && op.length_params.len_n != 0)
	{
		printf("\nThe '-n' option is not compatible with the '-m1' and '-m2' options\n");
		return -1;
	}

	if (op.length_params.len_m1 > op.length_params.len_m2)
	{
		printf("\nThe minimum password length cannot be greater than the maximum\n");
		return -1;
	}

	if (op.alph.a && op.def_alph.C)
	{
		printf("\nOptions '-C' and '-a' are not compatible!\n");
		return -1;
	}

	if ((op.alph.a == false && op.def_alph.C == false))
	{
		printf("\nThe alphabet set for the password is not set!\n");
		return -1;
	}

	if ((op.length_params.len_m1 < 10 && op.length_params.m1) || (op.length_params.len_m2 > 100 && op.length_params.m2) || (op.length_params.len_n > 100 && op.length_params.n))
	{
		printf("\nIncorrect password length range\n");
		return -1;
	}

	if ((op.length_params.len_n == 0 && op.length_params.n) || (op.length_params.len_m1 == 0 && op.length_params.m1) || (op.length_params.len_m2 == 0 && op.length_params.m2))
	{
		printf("\nEncountered 0 length password\n");
		return -1;
	}
	return 0;
}

int generate_password()
{
	size_t len_pass = 0, tmp = 1, length = 1;
	char optA[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" },
		opta[] = { "abcdefghijklmnopqrstuvwxyz" },
		optD[] = { "0123456789" },
		optS[] = { "!#$'()*+,./:;=?@[]^_`{}" },
		*userALPH;

	if (!op.length_params.m1 && !op.length_params.m2 && !op.length_params.n)
	{
		len_pass = 10;
	}
	userALPH = (char*)malloc((tmp) * sizeof(char));
	if (userALPH == NULL)
	{
		printf("Memory allocated incorrectly");
		return -1;
	}
	for (size_t i = 0; i < tmp; i++)
		userALPH[i] = '\0';
	if (op.alph.a)
		tmp = strlen(op.alph.alphabet);
	else
	{
		if (op.def_alph.A)
			tmp += strlen(optA);
		if (op.def_alph.a)
			tmp += strlen(opta);
		if (op.def_alph.S)
			tmp += strlen(optS);
		if (op.def_alph.D)
			tmp += strlen(optD);
	}

	
	unsigned int  pos = 0, pass_count = op.count.c_count;

	if (op.def_alph.A)
	{
		length += strlen(optA);
		strcat_s(userALPH, length, optA);
	}
	if (op.def_alph.a)
	{
		length += strlen(opta);
		strcat_s(userALPH, length, opta);
	}
	if (op.def_alph.D)
	{
		length += strlen(optD);
		strcat_s(userALPH, length, optD);
	}
	if (op.def_alph.S)
	{
		length += strlen(optS);
		strcat_s(userALPH, length, optS);
	}
	if (op.alph.a)
	{
		length += strlen(op.alph.alphabet);
		strcat_s(userALPH, length, op.alph.alphabet);
	}
	if (op.length_params.n)
		len_pass = op.length_params.len_n;

	for (size_t i = 0; i < pass_count; i++)
	{
		if (op.length_params.len_n == 0 && op.length_params.m1 && op.length_params.m2)
			len_pass = op.length_params.len_m1 + rand() % (op.length_params.len_m2 - op.length_params.len_m1);

		password = (char*)malloc((len_pass + 1) * sizeof(char));
		if (password == NULL)
		{
			printf("Memory allocated incorrectly");
			return -1;
		}
		password[len_pass] = '\0';
		
		for (size_t j = 0; j < len_pass; j++)
		{
			pos = rand() % (length - 1);
			password[j] = userALPH[pos];
		}

		printf("\n%zu)%s", i, password);
		free(password);
	}
	return 0;
}

void func_for_debug()
{
	if (op.alph.a)
		printf("\n-a parameter: %s", op.alph.alphabet);
	if (op.count.c)
		printf("\n-c parameter: %d", op.count.c_count);
	if (op.length_params.m1 && op.length_params.m2)
		printf("\n-m1 m2 parameteres: %d %d", op.length_params.len_m1, op.length_params.len_m2);
	if (op.length_params.n)
		printf("\n-n parameter: %d", op.length_params.len_n);
	if (op.def_alph.C)
	{
		printf("\n-C parameters: ");
		if (op.def_alph.A)
			printf("A ");
		if (op.def_alph.a)
			printf("a ");
		if (op.def_alph.S)
			printf("S ");
		if (op.def_alph.D)
			printf("D ");
	}
	printf("\n");
}
int checker(int argc, char** argv)
{
	if (check_options(argc, argv) == 0)
	{
		if (check_conflict_options() == 0)
		{
			func_for_debug();
			if (generate_password() != 0)
				return -1;
		}
		else
			return -1;
	}
	else
		return -1;
	return 0;
}

