#include <stdlib.h>

int	get_final_length(long int nbr, int base_len)
{
	int	len;

	if (nbr < 0)
		nbr = -nbr;
	len = 0;
	while (nbr > 0 || len == 0)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}

char	*convert_nbr_base(long int nbr, char *base, int base_len)
{
	char	c;
	int		cursor;
	char	*result;
	int		nbr_final_len;
	int		is_negative;

	is_negative = nbr < 0;
	nbr_final_len = get_final_length(nbr, base_len);
	result = malloc(sizeof(char) * (nbr_final_len + 1 + is_negative));
	if (!result)
		return (0);
	cursor = 0;
	if (is_negative)
		result[cursor++] = '-';
	if (is_negative)
		nbr = -nbr;
	while (cursor - is_negative < nbr_final_len)
	{
		c = base[nbr % base_len];
		result[nbr_final_len + is_negative - (cursor - is_negative) - 1] = c;
		nbr = nbr / base_len;
		cursor++;
	}
	result[cursor] = '\0';
	return (result);
}
