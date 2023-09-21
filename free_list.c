#include "monty.h"

/**
 * free_list - free all the linked list
 * @data: my data that containe my DLL
 */

void	free_list(data_t *data)
{
	stack_t	*temp;

	while (data->stack)
	{
		temp = data->stack->next;
		free(data->stack);
		data->stack = temp;
	}
}
