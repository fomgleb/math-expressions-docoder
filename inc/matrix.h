#pragma once

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct s_unknown_num {
	bool is_negative;
	int digits_count;
	char *digits;
} t_unknown_num;

typedef struct s_operator {
	int (*function)(int, int);
	char symbol;
} t_operator;

typedef struct s_intarr {
	int *arr;
	int size;
} t_intarr;

char *mx_strdup(const char *str);
int *mx_intarrdup(const int *arr, int size);

bool mx_isdigit(int c);
bool mx_isspace(char c);

int mx_atoi(const char *str);
t_unknown_num mx_str_to_number(char *str);
t_operator mx_str_to_operator(const char *str);

int mx_get_number_rank(int digits_count);
t_intarr mx_get_possible_numbers(t_unknown_num num);

void mx_print_error(const char *message);
void mx_print_three_errors(const char *msg1, const char *msg2, const char *msg3);
void mx_printchar(char c);
void mx_printint(int n);
void mx_print_calculation(int a, char operator, int b, int result);
void mx_print_available_calculations(t_unknown_num op1, t_operator oprtr, t_unknown_num op2, t_unknown_num res);

int mx_plus(int a, int b);
int mx_minus(int a, int b);
int mx_multiply(int a, int b);
int mx_divide(int a, int b);

char *mx_strnew(const int size);
int mx_strlen(const char *s);
char *mx_strcpy(char *dst, const char *src);
void mx_replace_one_symbol_with_another(char *str, char one, char another);
int mx_count_repetitions(const char *str, char c);
t_intarr mx_get_coincidences_indexes(const char *str, int size, char c);

