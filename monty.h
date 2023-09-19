#ifndef _MONTY_H_
#define _MONTY_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char **_split(char *str, char *lim);
void	free_split(char **arr);
void	fd_putstr(char *str, int fd);
void	putError(char *s1, char *s2);
/**
 * struct data_s - my all data
 * @fd: the file descriptor of bytecode file
 * @stack: the stack
 * @exec: the opcode
 * Description: all data needed
 */

typedef struct data_s
{
	int	fd;
	stack_t	*stack;
	instruction_t	*exec;
} data_t;

#endif /* _MONTY_H_ */
