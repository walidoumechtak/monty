#include "monty.h"

/**
 * _strdup - copy a string i heap
 * @str: the string should be copyed
 * Return: the new string
 */

char	*_strdup(char *str)
{
	char	*new;
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	new = malloc(sizeof(char) * (strlen(str) + 1));
	if (!new)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
