/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:25:23 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/09 18:32:21 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* This is one of the most important functions that I made, now without the
 * need for 2 functions for positive and negative types. The secret is...
 * The first character of the base tells the function if it should be treated
 * like an positive or negative number, the special character is '-'. */
int	ft_based(size_t n, char *base)
{
	int		len;
	size_t	base_len;

	len = 0;
	base_len = ft_strlen(&base[1]);
	if (base[0] == '-' && (ssize_t)n < 0)
	{
		n = (size_t)(-(ssize_t)n);
		len += write(1, "-", 1);
	}
	if (n >= (size_t)base_len)
		len += ft_based(n / base_len, base);
	len += write(1, &base[(n % base_len) + 1], 1);
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

int	ft_nbrlen(ssize_t nbr, int base_len)
{
	size_t	n;
	int		len;

	len = 0;
	n = nbr;
	if (nbr == 0)
		return (1);
	if (base_len < 0)
	{
		if (nbr < 0)
		{
			len++;
			n = -nbr;
		}
		base_len = -base_len;
	}
	while (n)
	{
		n /= base_len;
		len++;
	}
	return (len);
}
