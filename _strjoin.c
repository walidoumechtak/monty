#include "monty.h"

/**
 * _strjoin - join two string
 * @s1: the first string
 * @s2: the second string
 * Return: the new string joined
 */

char *_strjoin(char *s1, char *s2)
{
	int	len;
	char *new;
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (_strdup(s2));
	if (!s2)
		return (_strdup(s1));
	len = strlen(s1) + strlen(s2);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
	{
		fd_putstr("Error: malloc failed\n", 2);
		exit(EXIT_FAILURE);
	}
	while (s1[i])
		new[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new[j++] = s2[i++];
	new[j] = '\0';
	return (new);
}
