#include <stddef.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int	size;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	*range = (int *) malloc(sizeof(int) * size);
	if (*range == NULL)
		return (-1);
	i = -1;
	while (++i < size)
		(*range)[i] = min++;
	return (size);
}
