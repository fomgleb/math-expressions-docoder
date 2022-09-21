#include "../inc/matrix.h"

int mx_get_number_rank(int digits_count) {
	int rank = 1;
	for (int i = 0; i < digits_count; ++i) {
		rank *= 10;
	}
	return rank;
}

t_intarr mx_get_possible_numbers(t_unknown_num num) {
	int num_rank = mx_get_number_rank(mx_count_repetitions(num.digits, '?'));
	t_intarr possible_numbers = {NULL, 0};
	char *current_num_str = mx_strnew(num.digits_count);
	t_intarr unknown_digits_indexes = mx_get_coincidences_indexes(num.digits, num.digits_count, '?');

	mx_strcpy(current_num_str, num.digits);

	possible_numbers.arr = malloc(num_rank * sizeof(int));
	mx_replace_one_symbol_with_another(current_num_str, '?', '0');

	int number = 0;
	while (possible_numbers.size < num_rank) {

		int stored_number = number;
		for (int j = unknown_digits_indexes.size - 1; j >= 0; --j) {
			current_num_str[unknown_digits_indexes.arr[j]] = (char)((stored_number % 10) + 48);
			stored_number /= 10;
		}

		number++;

		possible_numbers.arr[possible_numbers.size] = mx_atoi(current_num_str);
		possible_numbers.size++;
	}

	if (num.is_negative)
		for (int i = 0; i < possible_numbers.size; ++i)
			possible_numbers.arr[i] *= -1;

	free(current_num_str);
	free(unknown_digits_indexes.arr);
	return possible_numbers;
}

