#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int main(int argc, char *argv[])
{
	char *result;

	result = ft_strjoin(argc - 2, argv + 2, argv[1]);
	printf("result: %s\n", result);
	free(result);
	char test[2000][2000];

	for (int i = 0; i < 2000; i++)
	{
		for (int j = 0; j < 1999; j++)
		{
			test[i][j] = 'a';
		}
		test[i][1999] = '\0';
		printf("%s\n", test[i]);
	}
}
