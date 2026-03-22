#include "get_next_line.h"
#include <stdlib.h>

int has_no_line(char *s)
{
	if (!s)
		return (1);
	while (*s)
	{
		if (*s == '\n')
			return (0);
		s++;
	}
	return (1);
}

char *extract_line(char *s, char **remain)
{
    int len = 0;
    char *line;

    while (s[len] != '\n' && s[len] != '\0')
        len++;
    line = ft_substr(s, 0, (s[len] == '\n') ? len + 1 : len);
    if (s[len] != '\0' && s[len + 1] != '\0')
        *remain = ft_substr(s, len + 1, ft_strlen(s) - (len + 1));
    else
        *remain = NULL;
    free(s);
    return (line);
}


char	*get_next_line(int fd)
{
	static char *cache;
	char *read_buf;
	int bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_buf = malloc(BUFFER_SIZE + 1);
	if (!read_buf)
		return (NULL);
	bytes_read = 1;
	while (has_no_line(cache) && bytes_read > 0)
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
            free(cache);
			free(read_buf);
            cache = NULL;
            return (NULL);
		}
		read_buf[bytes_read] = '\0';
		cache = ft_strjoin(cache, (const char*)read_buf);
	}
	free(read_buf);
	return(extract_line(cache, &cache));
}
