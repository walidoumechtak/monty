#include "monty.h"

/**
 * initData - init all the data of the program
 * @data: struct that containe all my data
 * @av: **av that containe arguments
 */

void	initData(data_t *data, char **av)
{
	data->stack = NULL;
	data->fd = open(av[1], O_RDONLY, 0644);
	if (data->fd < 0)
	{
		putError("Error: Can't open file ", av[1]);
		exit(EXIT_FAILURE);
	}
}

/**
 * main - the starting of the porgam
 * @ac: the size of argv
 * @av: an arrya that containe all arguments
 * Return: 0 on success or !0 when its fail
 */

int main(int ac, char **av)
{
	data_t	*data;

	data = malloc(sizeof(data_t));
	if (!data)
	{
		fd_putstr("Error: malloc failed\n", 2);
		exit(EXIT_FAILURE);
	}
	if (ac < 2 || ac > 2)
	{
		fd_putstr("USAGE: monty file\n", 2);
		exit(EXIT_FAILURE);
	}
	initData(data, av);
	readFile(data);
	runByteCode(data);
	free_list(data);
	free(data->exec);
	free(data->content);
	close(data->fd);
	free(data);
	return (0);
}
