#include <stdlib.h>

int *ft_range(int min, int max)
{
	int	i;
	int	*range;
	int	size;

	if (min >= max)
		return (0);
	size = max - min;
	range = (int *)malloc(sizeof(int) * size);
	if (range == 0)
		return (0);
	i = -1;
	while (++i < size)
		range[i] = min++;
	return range;
}
