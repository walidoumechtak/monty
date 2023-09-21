#include "monty.h"

/**
 * readFile - read all the file
 * @data: my data needed
 */

void readFile(data_t *data)
{
	char buffer[1024];
	int	read_size;
	char *res;
	char *temp;

	res = NULL;
	read_size = read(data->fd, buffer, 1024);
	if (read_size < 0)
		exit(EXIT_FAILURE);
	buffer[read_size] = '\0';
	res = _strjoin(buffer, res);
	while (read_size > 0)
	{
		read_size = read(data->fd, buffer, 1024);
		if (read_size <= 0)
			break;
		buffer[read_size] = '\0';
		temp = _strjoin(res, buffer);
		free(res);
		res = temp;
	}
	data->content = res;
}
