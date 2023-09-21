#include "monty.h"

/**
 * free_ressource - free all ressource that have been allocated
 * @data: my data
 */

void	free_ressource(data_t *data)
{
	free(data->content);
	free(data->stack);
	free(data->exec);
	close(data->fd);
	free(data);
}
