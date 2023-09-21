#include "monty.h"

/**
 * size_string - how many word in a string
 * @str: the string to search
 * @lim: the delimiter of word
 * Return: the length
 */

int	size_string(char *str, char *lim)
{
	char *temp;
	int	cpt;

	if (!str)
		return (0);
	str = _strdup(str);
	cpt = 0;
	temp = strtok(str, lim);
	while (temp != NULL)
	{
		cpt++;
		temp = strtok(NULL, lim);
	}
	free(str);
	return (cpt);
}

/**
 * _split - split a string on its delimiter
 * @str: the string should be stplited
 * @lim: delimiter to split the str
 * Return: return a **arr that containe all elements
 */

char **_split(char *str, char *lim)
{
	char	*temp;
	char **arr;
	int	words;
	int	i;

	i = 0;
	words = size_string(str, lim);
	arr = malloc(sizeof(char *) * (words + 1));
	str = _strdup(str);
	temp = strtok(str, lim);
	while (temp != NULL)
	{
		arr[i] = _strdup(temp);
		i++;
		temp = strtok(NULL, lim);
	}
	arr[i] = NULL;
	free(str);
	return (arr);
}
