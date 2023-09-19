#include "monty.h"

void	putError(char *s1, char *s2)
{
	fd_putstr(s1, 2);
	fd_putstr(s2, 2);
	fd_putstr("\n");
}
