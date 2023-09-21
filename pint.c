#include "monty.h"

/**
 * pint - print the top element of the stack
 * @stack: the stack
 * @line_number: the value of node
 */

void	pint(stack_t **stack, int line_number)
{
	char	c;

	if (stack == NULL || *stack == NULL)
	{
		fd_putstr("L", 2);
		c = ((line_number + 1) + '0');
		write(2, &c, 1);
		fd_putstr(": can't pint, stack empty\n", 2);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
