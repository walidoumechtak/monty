#include "monty.h"

/**
 * free_split - free the double pointer
 * @arr: the array should be freed
 */

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
