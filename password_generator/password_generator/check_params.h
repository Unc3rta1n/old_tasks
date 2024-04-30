#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	bool C;
	bool a;
	bool A;
	bool D;
	bool S;
}DEF_ALPH_OPT_Ñ;

typedef struct {
	bool a;
	char* alphabet;
}ALPH;

typedef struct {
	bool m1;
	bool m2;
	bool n;
	unsigned int len_m1;
	unsigned int len_m2;
	unsigned int len_n;
}LEN_OPT_M1_M2_N;
typedef struct {
	bool c;
	unsigned int c_count;
}COUNT;

typedef struct {
	DEF_ALPH_OPT_Ñ def_alph;
	LEN_OPT_M1_M2_N length_params;
	ALPH alph;
	COUNT count;
} option;

option op;
char* password;

void init_options(void);
int check_options(int argc, char** argv);
int is_digits(char var);
int check_a_option(char* argv);
int check_C_option(char* argv);
int check_conflict_options(void);
int generate_password(void);
void func_for_debug();
int checker(int argc, char** argv);