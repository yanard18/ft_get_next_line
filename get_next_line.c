#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char	*get_next_line(int fd)
{
	char *buf;
	int bytes_read;

	buf = malloc(BUFFER_SIZE);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	buf[bytes_read] = '\0';
	return (buf);
}
