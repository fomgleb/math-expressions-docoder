#include "../inc/matrix.h"

int main(int argc, char **argv) {
	if (argc != 5) {
		mx_print_error("usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]\n");
		return 1;
	}

	t_unknown_num operand1 = mx_str_to_number(argv[1]);
	if (operand1.digits_count == 0)
		mx_print_three_errors("Invalid operand: ", argv[1], "\n");
	t_unknown_num operand2 = mx_str_to_number(argv[3]);
	if (operand2.digits_count == 0) {
		free(operand1.digits);
		mx_print_three_errors("Invalid operand: ", argv[3], "\n");
	}
	t_operator operator = mx_str_to_operator(argv[2]);
	if (operator.symbol == '\0') {
		free(operand1.digits);
		free(operand2.digits);
		mx_print_three_errors("Invalid operator: ", argv[2], "\n");
	}
	t_unknown_num result = mx_str_to_number(argv[4]);
	if (result.digits_count == 0) {
		free(operand1.digits);
		free(operand2.digits);
		mx_print_three_errors("Invalid result: ", argv[4], "\n");
	}

	mx_print_available_calculations(operand1, operator, operand2, result);

	free(operand1.digits);
	free(operand2.digits);
	free(result.digits);

	return 0;
}

