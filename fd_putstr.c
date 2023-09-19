#include "monty.h"

/**
 * _putchar - put a char to fd
 * @c: the charactere to push
 * @fd: the fd to put c
 */

void	_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

/**
 * fd_putstr - put the string to fd
 * @str: the string to put
 * @fd: the fd to of
 */

void	fd_putstr(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		_putchar(str[i++], fd);
}
