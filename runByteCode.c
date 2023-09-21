#include "monty.h"

/**
 * checkIsDigit - check if a string is digit
 * @str: the string
 * Return: 1 if all is digit 0 if not
 */

int	checkIsDigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

/**
 * invalidOpCode - exit if opcode is invalid
 * @data: my data
 * @i: the line number
 * @cnt: the cntroll for error
 */

void	invalidOpCode(data_t *data, int i, int cnt)
{
	char	c;

	c = (i + 1) + '0';
	fd_putstr("L", 2);
	write(2, &c, 1);
	if (cnt == 0)
		putError(": unknown instruction ", data->opCode[0]);
	else if (cnt == 1)
		fd_putstr(": usage: push integer\n", 2);
	free_split(data->opCode);
	free_split(data->opCodes);
	free_ressource(data);
	exit(EXIT_FAILURE);
}

/**
 * cases - all cases of opcod
 * @data: my data
 * @i: line number
 */

void	cases(data_t *data, int i)
{
	int	temp;

	temp = 1;
	if (strcmp(data->opCode[0], "push") == 0)
	{
		if (data->opCode[1] == NULL || checkIsDigit(data->opCode[1]) == 0)
			invalidOpCode(data, i, 1);
		data->exec->f = push;
	}
	else if (strcmp(data->opCode[0], "pall") == 0)
		data->exec->f = pall;
	else if (strcmp(data->opCode[0], "pint") == 0)
		data->exec->f = pint;
	else if (strcmp(data->opCode[0], "pop") == 0)
		data->exec->f = pop;
	else if (strcmp(data->opCode[0], "nop") == 0)
		temp = 0;
	else if (strcmp(data->opCode[0], "swap") == 0)
		data->exec->f = swap;
	else if (strcmp(data->opCode[0], "add") == 0)
		data->exec->f = add;
	else
		invalidOpCode(data, i, 0);
	if (temp == 1)
	{
		if (data->opCode[1])
			data->exec->f(&data->stack, atoi(data->opCode[1]));
		else
			data->exec->f(&data->stack, i);
	}
}

/**
 * runByteCode - run the byte code
 * @data: my all data
 */

void	runByteCode(data_t *data)
{
	int	i;

	i = 0;
	data->opCodes = _split(data->content, "\n");
	data->exec = malloc(sizeof(instruction_t));
	if (!data->exec)
	{
		fd_putstr("Error: malloc failed\n", 2);
		free_ressource(data);
		exit(EXIT_FAILURE);
	}
	while (data->opCodes[i])
	{
		data->opCode = _split(data->opCodes[i], " ");
		data->exec->opcode = data->opCode[0];
		cases(data, i);
		i++;
		free_split(data->opCode);
	}
	free_split(data->opCodes);
}
