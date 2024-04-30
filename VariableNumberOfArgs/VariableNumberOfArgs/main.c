#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int sum_int(int n, ...)
{
	int result = 0;
	int* ptr = &n;
	++ptr;
	while (n > 0)
	{
		result += *ptr;
		++ptr;
		--n;
	}
	return result;
}

int sum_int_via_stdargMACROSES(int n, ...)
{
	va_list arglist;
	va_start(arglist, n);
	int result = 0, i = 0;
	while (n > 0)
	{
		i = va_arg(arglist, int);
		result += i;
		--n;
	}
	va_end(arglist);
	return result;
}

double sum_double(double n, ...)
{
	double result = 0;
	double* ptr = &n;
	++ptr;
	while (n > 0)
	{
		result += *ptr;
		++ptr;
		--n;
	}
	return result;
}

double sum_double_via_stdargMACROSES(int n, ...)
{
	double sum = 0.0, tmp;
	va_list argptr;


	va_start(argptr, n);
	for (; n; n--) {
		tmp = va_arg(argptr, double);
		sum += tmp;
	}


	va_end(argptr);

	return sum;
}

char* concat_with_numbers_params(int n, ...)
{
	va_list argptr;
	va_start(argptr, n);
	int counter = 0;
	char* tmp = va_arg(argptr, char*);
	do {
		int length = strlen(tmp);
		counter += length;
		tmp = va_arg(argptr, char*);
	} while (tmp != "\0");
	va_end(argptr);
	va_start(argptr, n);
	char* mass = (char*)malloc(sizeof(char) * counter);
	if (mass == NULL)
	{
		printf_s("not enough memory is available");
		exit(1);
	}
	else
	{
		int ptr = 0;
		for (; n; n--) {
			char* tmp = va_arg(argptr, char*);
			if (tmp == "\0" || tmp == '\0')
			{
				mass[ptr] = '\0';
				break;
			}
			int length = strlen(tmp);
			for (int i = 0; i < length; i++)
			{
				mass[ptr] = tmp[i];
				ptr++;
			}
		}
	}
	va_end(argptr);
	return mass;
}

char* concat(char* first, ...)
{
	va_list argptr;
	int counter = 0;
	char* tmp;
	tmp = first;
	va_start(argptr, first);
	do {
		int length = strlen(tmp);
		counter += length;
		tmp = va_arg(argptr, char*);
	} while (tmp != "\0");
	va_end(argptr);
	char* mass = (char*)malloc(sizeof(char) * counter);
	tmp = first;
	int ptr = 0;
	int length = 0;
	va_start(argptr, first);
	if (mass == NULL)
	{
		printf_s("not enough memory");
		exit(1);
	}
	else
	{
		do {
			if (tmp != NULL)
			{
				length = strlen(tmp);
			}
			else
			{
				printf_s("123");
				exit(1);
			}
			for (int i = 0; i < length; i++)
			{
				mass[ptr] = tmp[i];
				ptr++;
			}
			tmp = va_arg(argptr, char*);
		} while (tmp != "\0");
		va_end(argptr);
		mass[ptr] = '\0';
		return mass;
	}
}

int main()
{
	printf("%s\n", concat("Happy ", "new ", "year!", "\0"));
	printf("%s\n", concat_with_numbers_params(5, "one ", "two ", "three ", "four", "\0"));
	printf("%d\n", sum_int(4, 1, 2, 3, 4));
	printf("%d\n", sum_int_via_stdargMACROSES(4, 1, 2, 3, 4));
	printf("%lf\n", sum_double(4, 1.1, 2.2, 3.0, 0.1));
	printf("%lf\n", sum_double_via_stdargMACROSES(4, 1.1, 2.2, 3.0, 0.1));
	system("pause");
	return 0;
}