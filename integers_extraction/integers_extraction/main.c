#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int main(void) {
	char mass[1000] = { 0 };
	char digit[1000];
	int i = 0;
	char c;
	unsigned long long int digitsqr;
	printf_s("ENTER ENTER+CTRL+Z+ENTER TO END\n");
	while ((c = getchar()) != EOF)
	{	
		mass[i] = c;
		i++;
	}
	i = 0;
	while (mass[i]!='\0')
	{
		int j = 0;
		while (isdigit(mass[i]) == 0) {
			i++;
			if (i == strlen(mass))
			{
				exit(1);
			}
		}
		while (isdigit(mass[i]))
		{
			digit[j] = mass[i];
			i++;
			j++;
		}
		digit[j] = '\0';
		digitsqr = atoi(digit);
		printf_s("\nsquare from %lld = %lld ", digitsqr, (digitsqr * digitsqr));
	}
}