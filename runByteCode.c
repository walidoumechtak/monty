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
 * @opCodes: opcodes
 * @opCode: the opcode
 * @i: the line number
 * @cnt: the cntroll for error
 */

void	invalidOpCode(data_t *data, char **opCodes, char **opCode, int i, int cnt)
{
	char	c;

	c = (i + 1) + '0';
	fd_putstr("L", 2);
	write(2, &c, 1);
	if (cnt == 0)
		putError(": unknown instruction ", opCode[0]);
	else if (cnt == 1)
		fd_putstr(": usage: push integer\n", 2);
	free_split(opCode);
	free_split(opCodes);
	free_ressource(data);
	exit(EXIT_FAILURE);
}

/**
 * runByteCode - run the byte code
 * @data: my all data
 */

void	runByteCode(data_t *data)
{
	char **opCodes;
	char **opCode;
	int	i;

	i = 0;
	opCodes = _split(data->content, "\n");
	data->exec = malloc(sizeof(instruction_t));
	if (!data->exec)
	{
		fd_putstr("Error: malloc failed\n", 2);
		free_ressource(data);
		exit(EXIT_FAILURE);
	}
	while (opCodes[i])
	{
		opCode = _split(opCodes[i], " ");
		data->exec->opcode = opCode[0];
		if (strcmp(opCode[0], "push") == 0)
		{
			if (opCode[1] == NULL || checkIsDigit(opCode[1]) == 0)
				invalidOpCode(data, opCodes, opCode, i, 1);
			data->exec->f = push;
		}
		else if (strcmp(opCode[0], "pall") == 0)
			data->exec->f = pall;
		else if (strcmp(opCode[0], "pint") == 0)
			data->exec->f = pint;
		else
			invalidOpCode(data, opCodes, opCode, i, 0);
		if (opCode[1])
			data->exec->f(&data->stack, atoi(opCode[1]));
		else
			data->exec->f(&data->stack, i);
		i++;
		free_split(opCode);
	}
	free_split(opCodes);
}
