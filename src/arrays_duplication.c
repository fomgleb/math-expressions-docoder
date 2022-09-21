#include "../inc/matrix.h"

char *mx_strdup(const char *str) {
	if (str == NULL) return NULL;
	int str_len = mx_strlen(str);
	char *new_str = mx_strnew(str_len);
	if (new_str == NULL) return NULL;
	mx_strcpy(new_str, str);
	return new_str;
}

int *mx_intarrdup(const int *arr, int size) {
	if (arr == NULL) return NULL;
	int *new_arr = malloc(size * sizeof(int));
	for (int i = 0; i < size; ++i) {
		new_arr[i] = arr[i];
	}
	return new_arr;
}

