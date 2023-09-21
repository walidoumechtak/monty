#include "monty.h"

/**
 * putError - put the error to stderr
 * @s1: the frist string
 * @s2: the second string
 */

void	putError(char *s1, char *s2)
{
	fd_putstr(s1, 2);
	fd_putstr(s2, 2);
	fd_putstr("\n", 2);
}
