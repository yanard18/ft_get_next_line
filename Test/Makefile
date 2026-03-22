all:
	cc -Wextra -Wall -Werror -g -I../ test.c ../get_next_line.c -D BUFFER_SIZE=1024
	valgrind --leak-check=full ./a.out
