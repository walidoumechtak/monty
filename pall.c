#include "monty.h"

/**
 * pall - print all elelment of the stack
 * @stack: the stack to print
 * @line_number: usless
 */

void	pall(stack_t **stack, int line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
