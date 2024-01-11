/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:25:23 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/10 15:07:59 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_based(size_t n, char *base)
{
	int		len;
	size_t	base_len;

	len = 0;
	base_len = ft_strlen(base);
	if (n >= base_len)
		len += ft_based(n / base_len, base);
	len += write(1, &base[n % base_len], 1);
	return (len);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
	}
	return (NULL);
}

int	ft_isnbr(int c)
{
	unsigned char	chr;

	chr = c;
	return (chr >= '0' && chr <= '9');
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_nbrlen(size_t nbr, int base_len)
{
	int		len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}
