#include "../inc/matrix.h"

bool mx_isdigit(int c) {
	if (c >= 48 && c <= 57)
		return 1;
	return 0;
}

bool mx_isspace(char c) {
	if (c >= 9 && c <= 13)
		return 1;
	if (c == 32)
		return 1;
	return 0;
}

