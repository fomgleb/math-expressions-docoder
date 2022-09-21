#include "../inc/matrix.h"

char *mx_strnew(const int size) {
	if (size <= -1) return NULL;
	char *string = malloc((size + 1) * sizeof(char));
	if (string == NULL) return NULL;
	for (int i = 0; i < size + 1; ++i)
		string[i] = '\0';
	return string;
}

int mx_strlen(const char *s) {
	int length = 0;
	while (s[length] != '\0')
		length++;
	return length;
}

char *mx_strcpy(char *dst, const char *src) {
	for (int i = 0; src[i] != '\0'; i++)
		dst[i] = src[i];
	return dst;
}

void mx_replace_one_symbol_with_another(char *str, char one, char another) {
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] == one) {
			str[i] = another;
		}
	}
}

int mx_count_repetitions(const char *str, char c) {
	int repetitions_count = 0;
	for (int i = 0; str[i] != '\0'; ++i)
		if (str[i] == c)
			repetitions_count++;
	return repetitions_count;
}

t_intarr mx_get_coincidences_indexes(const char *str, int size, char c) {
	int coincidences_static[size];
	int coincedences_len = 0;

	for (int i = 0; i < size; ++i) {
		if (str[i] == c) {
			coincidences_static[coincedences_len] = i;
			coincedences_len++;
		}
	}

	t_intarr result = {NULL, 0};
	result.size = coincedences_len;
	result.arr = mx_intarrdup(coincidences_static, coincedences_len);
	return result;
}

