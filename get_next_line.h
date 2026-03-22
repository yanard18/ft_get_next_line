#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_cache
{
	char *str;
	int nlines;
} t_cache;

char	*get_next_line(int fd);

#endif
