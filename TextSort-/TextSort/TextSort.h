#pragma once
#define ROWS 20
int compare(const void* str1, const void* str2);
void file_open(char name[]);
int filenames(void);
void file_read(void);
void qsort_print(void);
char ch;

char* arr_str[ROWS];
char buffer[200];
char* File_Names[10];