all: part_of_the_matrix clean

part_of_the_matrix inc/*.h src/*.c:
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic src/*.c -o part_of_the_matrix

uninstall: clean
	rm -rf part_of_the_matrix

clean:

reinstall: uninstall all

