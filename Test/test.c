#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

#define RED   "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

void test(char *exp, char *res)
{
	if (!res)
		return ;
	if (strcmp(exp, res) == 0)
	{
		printf(GREEN "[+] exp/res: %s" RESET "\n", exp);
	}
	else
	{
		printf(RED "[-] exp: %s, res:%s" RESET "\n", exp, res);
	}
	free(res);
}

int	main(void)
{
	int fd = open("lc.txt", O_RDONLY);
	/* work for BUFFER_SIZE=1024 */
	test("That is not dead\n", get_next_line(fd));
	test("which can eternal lie,\n", get_next_line(fd));
	test("even death may die.", get_next_line(fd));
	return (0);
}
