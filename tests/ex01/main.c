#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max);

int	main(void)
{
	int *range;
	int	i;

	// 3, 4, 5, 6, 7, 8, 9
	range = ft_range(3, 10);
	i = -1;
	printf("ft_range(3, 10);\n");
	while (++i < 10)
		printf("  deve ser %d, e é %d\n", i + 3 < 10 ? i + 3 : 0, range[i]);
	free(range);
	range = ft_range(10, 10);
	printf("ft_range(10, 10);\n");
	if (range == NULL)
		printf("  range is correctly NULL\n");
	else
		printf("  WRONG: range is not NULL\n");
	free(range);
}
