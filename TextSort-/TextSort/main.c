#include <stdio.h>
#include <stdlib.h> /* prototype exit() */
#include <string.h>
#include <locale.h>
#include<Windows.h>
#include <assert.h>
#include "TextSort.h"
int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "RU-ru");
	char* name=" ";
	int returned_Value= filenames();
	if (argv[1]!=NULL)
	{
    name = argv[1];
	}
	else 
	{
		if (returned_Value == 0)
		{
			char buffer[25];
			puts("¬ведите название файла:");
			fgets(buffer, 25, stdin);
			puts("\n");
			if (buffer[strlen(buffer)-1] == '\n') buffer[strlen(buffer)-1] = '\0';
			name = buffer;
		}	
	}
	if (returned_Value == 0)
	{
		file_open(name);
		file_read();
		system("pause");
		system("cls");
		qsort(arr_str, ROWS, sizeof(char*), compare);
		qsort_print();
	}
}


