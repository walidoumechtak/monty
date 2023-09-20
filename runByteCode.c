#include "monty.h"

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
			data->exec->f = push(stack, i + 1);
		else if (strcmp(opCode[0], "pall") == 0)
			data->exec->f = pall(stack, i + 1);
		else
		{
			fd_putstr("L", 2);
			write(2, ((i + 1) + '0'), 1);
			putError(": unknown instruction ", opCode[0]);
			free_split(opCode);
			free_split(opCodes);
			free_ressource(data);
			exit(EXIT_FAILURE);
		}
		i++;
		free_split(opCode);
	}
	free_split(opCodes);
}
