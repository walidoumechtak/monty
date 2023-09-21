#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: the stack
 * @line_number - the number of line where add occure
 */

void	add(stack_t **stack, int line_number)
{
	int	res;
	stack_t	*new;
	stack_t	*temp;
	int	i;
	char	c;

	i = 0;
	res = 0;
	temp = *stack;
	if (!stack || *stack == NULL || len_list(*stack) < 2)
	{
		c = (line_number + 1) + '0';
		fd_putstr("L", 2);
		write(2, &c, 1);
		fd_putstr(": can't add, stack too short\n", 2);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (!new)
		exit(EXIT_FAILURE);
	res += temp->n;
	res += temp->next->n;
	new->n = res;
	while (i < 2)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
		i++;
	}
	new->prev = NULL;
	new->next = *stack;
	*stack = new;
}
