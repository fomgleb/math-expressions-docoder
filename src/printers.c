#include "../inc/matrix.h"

void mx_print_error(const char *message) {
	write(2, message, mx_strlen(message));
}

void mx_print_three_errors(const char *msg1, const char *msg2, const char *msg3) {
	mx_print_error(msg1);
	mx_print_error(msg2);
	mx_print_error(msg3);
	exit(1);
}

void mx_printchar(char c) {
	write(1, &c, 1);
}

void mx_printint(int n) {
	if (n == 0) {
		mx_printchar('0');
		return;
	}
	int string_length = 11;
	char string[string_length];
	bool is_negative = n < 0;

	if (is_negative) {
		n *= -1;
		mx_printchar('-');
	}
	for (string_length = 0; n != 0; n /= 10) {
		string[string_length] = n % 10 + 48;
		string_length++;
	}
	for (int i = string_length - 1; i >= 0; i--)
		mx_printchar(string[i]);
}

void mx_print_calculation(int a, char operator, int b, int result) {
	mx_printint(a);
	mx_printchar(' ');
	mx_printchar(operator);
	mx_printchar(' ');
	mx_printint(b);
	mx_printchar(' ');
	mx_printchar('=');
	mx_printchar(' ');
	mx_printint(result);
	mx_printchar('\n');
}

t_operator *mx_get_all_operators() {
	t_operator *all_operators = malloc(4 * sizeof(t_operator));
	all_operators[0].symbol = '+';
	all_operators[0].function = mx_plus;
	all_operators[1].symbol = '-';
	all_operators[1].function = mx_minus;
	all_operators[2].symbol = '*';
	all_operators[2].function = mx_multiply;
	all_operators[3].symbol = '/';
	all_operators[3].function = mx_divide;
	return all_operators;
}

void mx_print_available_calculations(t_unknown_num op1, t_operator oprtr, t_unknown_num op2, t_unknown_num res) {
	t_intarr op1_poss = mx_get_possible_numbers(op1);
	t_intarr op2_poss = mx_get_possible_numbers(op2);
	t_intarr res_poss = mx_get_possible_numbers(res);
	t_operator *operators = NULL;
	int operators_len = 1;
	if (oprtr.function == NULL) {
		operators = mx_get_all_operators();
		operators_len = 4;
	} else {
		operators = malloc(sizeof(t_operator));
		operators[0] = oprtr;
	}

	for (int oprtr_i = 0; oprtr_i < operators_len; ++oprtr_i) {
		for (int op1_i = 0; op1_i < op1_poss.size; ++op1_i) {
			for (int op2_i = 0; op2_i < op2_poss.size; ++op2_i) {
				if (operators[oprtr_i].symbol == '/' && op2_poss.arr[op2_i] == 0)
					continue;
				for (int res_i = 0; res_i < res_poss.size; ++res_i) {
					if (operators[oprtr_i].function(op1_poss.arr[op1_i], op2_poss.arr[op2_i]) == res_poss.arr[res_i])
						mx_print_calculation(op1_poss.arr[op1_i],
											 operators[oprtr_i].symbol,
											 op2_poss.arr[op2_i],
											 res_poss.arr[res_i]);
				}
			}
		}
	}

	free(op1_poss.arr);
	free(op2_poss.arr);
	free(operators);
	free(res_poss.arr);
}

