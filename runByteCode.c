#include "monty.h"

/**
 * runByteCode - run the byte code
 * @data: my all data
 */

void	runByteCode(data_t *data)
{
	char **opcodes;
	int	i;

	i = 0;
	opcodes = _split(data->content, "\n");
	while (opcodes[i])
	{
		printf("%d - %s\n", i + 1, opcodes[i]);
		i++;
	}
	free_split(opcodes);
}
