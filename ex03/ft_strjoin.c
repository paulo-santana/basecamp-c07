/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 01:31:54 by psergio-          #+#    #+#             */
/*   Updated: 2021/04/16 01:31:55 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (*str++)
		length++;
	return (length);
}

char	*ft_strcat(char *dest, char *src)
{
	int	dest_size;

	dest_size = 0;
	while (dest[dest_size] != 0)
		dest_size++;
	while (*src != '\0')
	{
		dest[dest_size] = *src;
		dest_size++;
		src++;
	}
	dest[dest_size] = '\0';
	return (dest);
}

/*
** Retorna o tamanho total que a string joinada tera quando for criada.
** O tamanho calculado considera os separadores no meio da string
*/

int		ft_total_length(int size, char **strs, char *sep)
{
	int	i;
	int	total_size;

	i = -1;
	total_size = 0;
	while (++i < size - 1)
		total_size += ft_strlen(strs[i]) + ft_strlen(sep);
	total_size += ft_strlen(strs[i]);
	return (total_size);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		total_size;
	char	*result;

	if (size <= 0)
	{
		result = (char *)malloc(sizeof(char));
		result[0] = '\0';
		return (result);
	}
	total_size = ft_total_length(size, strs, sep);
	result = (char *)malloc(sizeof(char) * (total_size + 1));
	if (!result)
		return (0);
	result[0] = 0;
	i = -1;
	while (++i < size - 1)
	{
		ft_strcat(result, strs[i]);
		ft_strcat(result, sep);
	}
	ft_strcat(result, strs[i]);
	return (result);
}
