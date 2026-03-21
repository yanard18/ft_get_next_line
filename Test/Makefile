all:
	cc -Wextra -Wall -Werror -I../ test.c ../get_next_line.c -D BUFFER_SIZE=1024
	valgrind ./a.out
