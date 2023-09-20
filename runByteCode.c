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
		free(data->exec);
		exit(EXIT_FAILURE);
	}
	while (opCodes[i])
	{
		opCode = _split(opCodes[i], " ");
		printf("opcde: %s, the value: %s\n", opCode[0], opCode[1]);
		i++;
		free_split(opCode);
	}
	free_split(opCodes);
}
