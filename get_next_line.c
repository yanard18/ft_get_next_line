#include "get_next_line.h"
#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substr;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if ((start >= s_len))
	{
		substr = malloc(1);
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc((sizeof(char) * len) + 1);
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*res;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = malloc(s1_len + s2_len + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		res[i] = s1[i];
	i = -1;
	while (++i < s2_len)
		res[s1_len + i] = s2[i];
	res[s1_len + s2_len] = '\0';
	if (s1)
		free(s1);
	return (res);
}

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
	char read_buf[BUFFER_SIZE + 1];
	int bytes_read;

	while (has_no_line(cache))
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			return (cache);
		}
		read_buf[bytes_read] = '\0';
		cache = ft_strjoin(cache, (const char*)read_buf);
	}
	return(extract_line(cache, &cache));
}
