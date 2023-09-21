#include "monty.h"

/**
 * push - push an element to the stack
 * @stack: the stack to push
 * @line_number: the number of the line where push exist
 */

void	push(stack_t **stack, int line_number)
{
	stack_t	*new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fd_putstr("Error: malloc failed\n", 2);
		exit(EXIT_FAILURE);
	}
	new->n = line_number;
	new->next = NULL;
	new->prev = NULL;
	if (stack == NULL)
		stack = &new;
	else if (*stack == NULL)
		*stack = new;
	else
	{
		(*stack)->prev = new;
		new->next = *stack;
		*stack = new;
	}
}
