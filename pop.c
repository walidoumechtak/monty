#include "monty.h"

/**
 * pop - pop a node from the top of the stack
 * @stack: my stack
 * @line_number: the line number where pop occure
 */

void	pop(stack_t **stack, int line_number)
{
	char	c;
	stack_t	*temp;

	if (stack == NULL || *stack == NULL)
	{
		fd_putstr("L", 2);
		c = (line_number + 1) + '0';
		write(2, &c, 1);
		fd_putstr(": can't pop an empty stack\n", 2);
		exit(EXIT_FAILURE);
	}
	else if (len_list(*stack) == 1)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
