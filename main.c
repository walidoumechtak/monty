#include "monty.h"

/**
 * initData - init all the data of the program
 * @data: struct that containe all my data
 */

void	initData(data_t * data)
{
        data->stack = malloc(sizeof(stack_t));
        data->exec = malloc(sizeof(instruction_t));
        if (!stack || !exec)
        {
                fd_putstr("Error: malloc failed\n");
                free(stack);
                free(exec);
                exit(EXIT_FAILURE);
        }
}

/**
 * main - the starting of the porgam
 * @ac: the size of argv
 * @argv: an arrya that containe all arguments
 * Return: 0 on success or !0 when its fail
 */

int main(int ac, char **av)
{
	int	fd;
	data_t	*data;

	data = malloc(sizeof(data_t));
	if (!data)
	{
		fd_putstr("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (ac > 2 || ac < 2)
	{
		fd_putstr("USAGE: monty file\n", 2);
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY, 0644);
	if (fd < 0)
	{
		fd_putstr("Error: Can't open file ");
		fd_putstr(av[1], 2);
		fd_putstr("\n");
		exit(EXIT_FAILURE);
	}
	runByteCode();
}
