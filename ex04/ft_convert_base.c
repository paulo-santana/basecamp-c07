#include <stdio.h>
#include <stdlib.h>

int		get_final_length(long int nbr, int base_size);
char	*convert_nbr_base(long int nbr, char *base, int base_len);

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' ||
		c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int		convert_to_int(char *str, char *base, int negative_multiplier)
{
	int nb;
	int base_size;
	int i;

	base_size = -1;
	while (base[++base_size] != 0)
		;
	nb = 0;
	while (*str)
	{
		i = -1;
		while (base[++i] != *str && i < base_size)
			;
		if (i < base_size)
			nb = nb * base_size + i;
		else
			return (0);
		str++;
	}
	return (nb * negative_multiplier);
}

/*
** Returns 0 if the specified base contains any whitespace, '+', '-' or
** repeated characters.
*/

int		is_base_valid(char *base)
{
	int		i;
	int		n;
	char	already_seen[128];

	i = 0;
	while (i < 128)
		already_seen[i++] = 0;
	i = 0;
	while (base[i] != '\0')
	{
		n = base[i];
		if (n == '-' || n == '+' || ft_isspace(n))
			return (0);
		if (already_seen[n] != 0)
			return (0);
		already_seen[n] = base[i];
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

int		ft_atoi_base(char *str, char *base)
{
	int sign_multiplier;

	while (*str)
		if (!ft_isspace(*str))
			break ;
		else
			str++;
	sign_multiplier = 1;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign_multiplier *= -1;
	return (convert_to_int(str, base, sign_multiplier));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	nbr_int;
	int			to_len;
	int			cursor;

	if (!is_base_valid(base_from) || !is_base_valid(base_to))
		return (0);
	nbr_int = ft_atoi_base(nbr, base_from);
	to_len = -1;
	while (base_to[++to_len])
		;
	return (convert_nbr_base(nbr_int, base_to, to_len));
}
