#include "monty.h"

/**
 * swap - swap two top element
 * @stack: the stack
 * @line_number: the number of line
 */

void	swap(stack_t **stack, int line_number)
{
	stack_t	*temp;
	char	c;

	if (stack == NULL || *stack == NULL || len_list(*stack) < 2)
	{
		c = (line_number + 1) + '0';
		fd_putstr("L", 2);
		write(2, &c, 1);
		fd_putstr(": can't swap, stack too short\n", 2);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->prev = NULL;
	(*stack)->prev = temp;
	temp->next = *stack;
	*stack = temp;
}
