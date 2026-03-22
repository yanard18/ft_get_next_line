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

char *extract_line(char **cache)
{
    int len = 0;
    char *line;
    char *temp;

    if (!cache || !*cache || **cache == '\0')
    {
        if (cache && *cache)
        {
            free(*cache);
            *cache = NULL;
        }
        return (NULL);
    }
    temp = *cache;
    while (temp[len] != '\n' && temp[len] != '\0')
        len++;
    line = ft_substr(temp, 0, (temp[len] == '\n') ? len + 1 : len);
    if (temp[len] != '\0' && temp[len + 1] != '\0')
        *cache = ft_substr(temp, len + 1, ft_strlen(temp) - (len + 1));
    else
        *cache = NULL;
    free(temp); // Free the original string
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
	return(extract_line(&cache));
}
