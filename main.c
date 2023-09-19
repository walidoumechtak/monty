#include "monty.h"

int main()
{
	char **arr = _split("walid and med are brothers", " ");

	int i = 0;
	while (arr[i])
	{
		printf("arr[%d] = %s\n", i, arr[i++]);
	}
	free_split(arr);
}
