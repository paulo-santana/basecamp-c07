#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max);

int	main(void)
{
	int *range;
	int **rangep;
	int	size;
	int	i;

	rangep = &range;
	size = ft_ultimate_range(rangep, 3, 10);
	i = -1;
	printf("ft_range(3, 10);\n");
		printf("   size is %d\n", size);
	while (++i < 10)
		printf("  should be %d, and is %d\n", i + 3 < 10 ? i + 3 : 0, range[i]);
	free(range);
	size = ft_ultimate_range(rangep, 10, 10);
	printf("ft_range(10, 10);\n");
	if (range == NULL)
		printf("  range is correctly NULL\n");
	else
		printf("  WRONG: range is not NULL\n");
	free(range);
}
