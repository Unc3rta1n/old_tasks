#include "TextSort.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <locale.h>
#include<Windows.h>
#include <assert.h>
FILE* file_in;
int numbers_of_names = 0;
void file_open(char name[]) {
	if ((fopen_s(&file_in, name, "r"))) {
		fprintf(stdout, "%s\n", "не могу отрыть файл для чтения");
		exit(EXIT_FAILURE);
	}
}
int filenames(void)
{
	if ((fopen_s(&file_in, "filenames.txt", "r"))) {
		fprintf(stdout, "%s\n", "\nне могу отрыть файл с именами для чтения\n");
		return 0;
	}
	else
	{
		fprintf_s(stdout, "\nнайден файл filenames.txt, считываю названия файлов с него...\n");
		while (!feof(file_in))
		{
			if (fgets(buffer, 200, file_in) != NULL)
			{
				File_Names[numbers_of_names] = (char*)malloc(strlen(buffer));
				int len_buffer = strlen(buffer);
				int j = 0;
				for (j; j < len_buffer; j++)
				{
					File_Names[numbers_of_names][j] = buffer[j];
				}
				if (File_Names[numbers_of_names][j-1] == '\n') 
				{
					File_Names[numbers_of_names][j - 1] = '\0';
				}
				File_Names[numbers_of_names][j] = '\0';
				numbers_of_names++;
			}
		}
	}
	for (int k = 0; k < numbers_of_names; k++)
	{
		file_open(File_Names[k]);
		file_read();
		system("pause");
		system("cls");
		qsort(arr_str, ROWS, sizeof(char*), compare);
		qsort_print();
		system("pause");
		system("cls");
	}
}

int compare(const void* str1, const void* str2) {
	char* a = *(char**)str1;
	char* b = *(char**)str2;
	return strlen(a) - strlen(b);
}
void file_read(void) {
	int i = 0;
	while (!feof(file_in))
	{
		if (fgets(buffer, 200, file_in) != NULL)
		{
			arr_str[i] = (char*)malloc(strlen(buffer));
			buffer[strlen(buffer) - 1] = '\0';
			int len_buffer = strlen(buffer);
			int j = 0;
			for (j; j < len_buffer; j++)
			{
				arr_str[i][j] = buffer[j];
			}
			arr_str[i][j] = '\0';
			puts(arr_str[i]);
			i++;
		}
	}
}
void qsort_print(void) {
	for (int i = 0; i < ROWS; i++)
	{
		puts(arr_str[i]);
	}
	puts(""); 
	puts("Файл успешно считан, текст отсортирован.");
}