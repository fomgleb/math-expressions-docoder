#include "../inc/matrix.h"

int mx_atoi(const char *str) {
	bool is_negative = false;
	int current_index = 0;
	int result_number = 0;
	for (; str[current_index] != '\0'; current_index++)
		if (!mx_isspace(str[current_index])) break;
	if (str[current_index] == '-') {
		is_negative = true;
		current_index++;
	}
	for (; mx_isdigit(str[current_index]); current_index++) {
		result_number *= 10;
		result_number += str[current_index] - 48;
	}
	if (is_negative) result_number *= -1;
	return result_number;
}

t_unknown_num mx_str_to_number(char *str) {
	int curr_index = 0;
	t_unknown_num result_number = {false, 0, NULL};
	int str_len = mx_strlen(str);
	char *digits = malloc((str_len + 1) * sizeof(char));
	digits[str_len] = '\0';

	for (; str[curr_index] != '\0'; curr_index++)
		if (!mx_isspace(str[curr_index])) break;
	if (str[curr_index] == '-') {
		result_number.is_negative = true;
		curr_index++;
	} else if (str[curr_index] == '+')
		curr_index++;

	for (; mx_isdigit(str[curr_index]) || str[curr_index] == '?'; curr_index++) {
		digits[result_number.digits_count] = str[curr_index];
		result_number.digits_count++;
	}

	for (; str[curr_index] != '\0' ; curr_index++) {
		if (!mx_isspace(str[curr_index])) {
			result_number.digits_count = 0;
		}
	}

	if (result_number.digits_count != 0) {
		digits[result_number.digits_count] = '\0';
		result_number.digits = mx_strdup(digits);
	}

	free(digits);
	return result_number;
}

t_operator mx_str_to_operator(const char *str) {
	int current_index = 0;
	t_operator operator = {NULL, '\0'};;
	for ( ; str[current_index] != '\0'; current_index++)
		if (!mx_isspace(str[current_index])) break;
	switch (str[current_index]) {
		case '+':
			operator.function = mx_plus;
			break;
		case '-':
			operator.function = mx_minus;
			break;
		case '/':
			operator.function = mx_divide;
			break;
		case '*':
			operator.function = mx_multiply;
			break;
		case '?':
			break;
		default:
			return operator;
	}
	operator.symbol = str[current_index];
	current_index++;
	for ( ; str[current_index] != '\0'; current_index++) {
		if (!mx_isspace(str[current_index])) {
			operator.function = NULL;
			operator.symbol = '\0';
			return operator;
		}
	}
	return operator;
}

