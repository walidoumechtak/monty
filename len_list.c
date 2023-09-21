#include "monty.h"

/**
 * len_list - calc the length of stack
 * @stack: the stack
 * Return: the length
 */

int	len_list(stack_t *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
