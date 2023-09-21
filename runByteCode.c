#include "monty.h"

/**
 * invalidOpCode - exit if opcode is invalid
 * @data: my data
 * @opCodes: opcodes
 * @opCode: the opcode
 */

void	invalidOpCode(data_t *data, char **opCodes, char ** opCode, int i)
{
	char	c;

	c = (i + 1) + '0';
	fd_putstr("L", 2);
	write(2, &c, 1);
	putError(": unknown instruction ", opCode[0]);
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
			data->exec->f = push;
		else if (strcmp(opCode[0], "pall") == 0)
			data->exec->f = pall;
		else
			invalidOpCode(data, opCodes, opCode, i);
		if (opCode[1])
			data->exec->f(&data->stack, atoi(opCode[1]));
		else
			data->exec->f(&data->stack, 0);
		i++;
		free_split(opCode);
	}
	free_split(opCodes);
}
