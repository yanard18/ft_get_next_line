CC = cc
CFLAGS = -Wextra -Wall -Werror -g -I../
FILES = test.c ../get_next_line.c ../get_next_line_utils.c
all:
	$(CC) $(CFLAGS) $(FILES) -D BUFFER_SIZE=1024
	valgrind --leak-check=full ./a.out
	$(CC) $(CFLAGS) $(FILES) -D BUFFER_SIZE=2048
	valgrind --leak-check=full ./a.out
	$(CC) $(CFLAGS) $(FILES) -D BUFFER_SIZE=100000
	valgrind --leak-check=full ./a.out
	$(CC) $(CFLAGS) $(FILES) -D BUFFER_SIZE=1
	valgrind --leak-check=full ./a.out
	$(CC) $(CFLAGS) $(FILES) -D BUFFER_SIZE=2
	valgrind --leak-check=full ./a.out
	$(CC) $(CFLAGS) $(FILES) -D BUFFER_SIZE=3
	valgrind --leak-check=full ./a.out
	$(CC) $(CFLAGS) $(FILES) -D BUFFER_SIZE=16
	valgrind --leak-check=full ./a.out
