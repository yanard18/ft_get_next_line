#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

void test(char *exp, char *res)
{
	if (strcmp(exp, res) == 0)
	{
		printf("[+] exp/res: %s\n", exp);
	}
	else
	{
		printf("[-] exp: %s, res:%s\n", exp, res);
	}
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
