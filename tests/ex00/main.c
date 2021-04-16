#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

char *ft_strdup(char *src);

int	main(void)
{
	char	*src;
	char	*dest;
	
	src = "kk eae blz";
	dest = ft_strdup(src);
	if (dest == NULL)
		printf("Null received. errno: %d\n", errno);
	else
		printf("%s\n", dest);
	free(dest);
}
